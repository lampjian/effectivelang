#include "model.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

typedef std::list<tileset *> patternlist;


struct patterns {
	patternlist background;
	patternlist patterns;
};


tileset *
init(int argc, char **argv, patterns & p)
{
	uint32_t shift = 0;

	tileset *first = NULL;
	for (int i = 1; i < argc; i++) {
		if (strcmp(argv[i], "-s") == 0 && i < argc - 1) {
			i++;
			shift = atoi(argv[i]);
			continue;
		}

		bool back = strcmp(argv[i], "-b") == 0 && i < argc - 1;

		if (back)
			i++;

		FILE *f = fopen(argv[i], "r");
		printf("Reading file %s\n", argv[i]);

		if (f == NULL) {
			fprintf(stderr, "File %s does not exist\n", argv[i]);
			exit(1);
		}
		tileset *t = new tileset(f, shift);
		fclose(f);

		if (first) {
			if (first->dimcnt() != t->dimcnt() || first->transcnt() != t->transcnt()) {
				fprintf(stderr, "Inconsistency with data dimensions\n");
				exit(1);
			}
		}
		else
			first = t;

		if (back)
			p.background.push_back(t);
		else
			p.patterns.push_back(t);
	}

	return first;
}


void
clear(patterns & p)
{
	for (patternlist::iterator it = p.background.begin(); it != p.background.end(); ++it)
		delete *it;
	for (patternlist::iterator it = p.patterns.begin(); it != p.patterns.end(); ++it)
		delete *it;
}

			

void
setdistance(patterns & p, uint32_t dimcnt, uint32_t tcnt)
{
	model back(tcnt, dimcnt);
	for (patternlist::iterator it = p.background.begin(); it != p.background.end(); ++it)
		back.add(**it);
	back.train();

	if (p.patterns.size() != 2) {
		fprintf(stderr, "Need to have exactly 2 datasets\n");
		exit(1);
	}

	model target(back);
	target.add(*p.patterns.front());
	target.train();

	tilelist re; 


	model cur(back);

	const tilelist & cands = p.patterns.back()->tiles();
	std::vector<bool> used(cands.size(), false);
	std::vector<const tile*> candvector(cands.begin(), cands.end());
	double bestdist = 0.99999;

	printf("\nCOMPUTING\n");

	while (true) {
		doublevector dists(cands.size(), 1);
		uint32_t done = 0;
#pragma omp parallel for
		for (uint32_t ind = 0; ind < cands.size(); ind++) {
			if (used[ind]) continue;
			printf("%ld %d\r", re.size(), done);
			done++;
			fflush(stdout);
			model cand(cur);
			cand.add(*p.patterns.front());
			cand.add(candvector[ind]);
			cand.train();

			model base(cur);
			base.add(candvector[ind]);
			base.train();

			dists[ind] = (cand.kl(base) + cand.kl(target)) / cand.kl(back);

			//if (e < 0.999) {
				//(*it)->print();
			//}

			//if (e < bestdist) {
				//bestdist = e;
				//best = candvector[ind];
				//bestind = ind;
			//}
		}

		uint32_t bestit = std::min_element(dists.begin(), dists.end()) - dists.begin();
		if (dists[bestit] >= bestdist) break;

		cur.add(candvector[bestit]);
		re.push_back(candvector[bestit]);
		used[bestit] = true;
		bestdist = dists[bestit];
	}
	printf("DONE\n");
	printf("%f\n", bestdist);
	print(re);
}



int
main(int argc, char ** argv)
{
	patterns p;
	tileset *first = init(argc, argv, p);

	if (first != NULL) {
		setdistance(p, first->dimcnt(), first->transcnt());
	}

	clear(p);
	return 0;
}

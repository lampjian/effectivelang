#include "model.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef std::list<tileset *> patternlist;


struct patterns {
	uint32_t mod, off;
	patternlist background;
	patternlist patterns;
};


tileset *
init(int argc, char **argv, patterns & p)
{
	uint32_t shift = 0;
	p.mod = 1;
	p.off = 0;

	tileset *first = NULL;
	for (int i = 1; i < argc; i++) {
		if (strcmp(argv[i], "-m") == 0 && i < argc - 1) {
			i++;
			p.mod = atoi(argv[i]);
			continue;
		}
		if (strcmp(argv[i], "-o") == 0 && i < argc - 1) {
			i++;
			p.off = atoi(argv[i]);
			continue;
		}
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

	//doublevector ent(p.patterns.size());
	std::vector<model *> ent(p.patterns.size());

	uint32_t ind = 0;
	for (patternlist::iterator it = p.patterns.begin(); it != p.patterns.end(); ++it, ind++) {
		printf("Training %d\r", ind);
		fflush(stdout);
		ent[ind] = new model(back);
		ent[ind]->add(**it);
		ent[ind]->train();
	}

	printf("\nCOMPUTING\n");

	ind = 0;
	for (patternlist::iterator it = p.patterns.begin(); it != p.patterns.end(); ++it, ind++) {

		uint32_t cnt = 1;
		model j(back);

		for (tilelist::const_iterator it2 = (*it)->tiles().begin(); it2 != (*it)->tiles().end(); ++it2, ++cnt) {
			j.add(*it2);

			if (cnt % p.mod != p.off) continue;

			j.train();
			//double je = j.entropy();
			double e = ent[ind]->kl(j) / (ent[ind]->kl(back) + 0.000001);
			printf("(%d, %f) ", cnt, e);
			
			fflush(stdout);
		}

		printf("\n");
	}

	for (uint32_t i = 0; i < ent.size(); i++)
		delete ent[i];
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

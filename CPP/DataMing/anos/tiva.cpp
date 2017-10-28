#include "model.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef std::list<tileset *> patternlist;


struct patterns {
	patternlist background;
	patternlist patterns;

	bool individual;
};


tileset *
init(int argc, char **argv, patterns & p)
{
	p.individual = false;
	uint32_t shift = 0;

	tileset *first = NULL;
	for (int i = 1; i < argc; i++) {
		if (strcmp(argv[i], "-i") == 0) {
			p.individual = true;
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
patdistance(patterns & p, uint32_t dimcnt, uint32_t tcnt)
{
	if (p.patterns.size() != 2) {
		fprintf(stderr, "Need exactly two pattern sets\n");
		return;
	}

	model back(tcnt, dimcnt);
	for (patternlist::iterator it = p.background.begin(); it != p.background.end(); ++it)
		back.add(**it);
	back.train();
	double be = back.entropy();

	const tilelist & t1 = p.patterns.front()->tiles();
	const tilelist & t2 = p.patterns.back()->tiles();

	doublevector ent1(t1.size());
	doublevector ent2(t2.size());

	uint32_t ind = 0;
	for (tilelist::const_iterator it = t1.begin(); it != t1.end(); ++it, ind++) {
		model m(back);
		m.add(*it);
		m.train();
		ent1[ind] = m.entropy();
	}

	ind = 0;
	for (tilelist::const_iterator it = t2.begin(); it != t2.end(); ++it, ind++) {
		model m(back);
		m.add(*it);
		m.train();
		ent2[ind] = m.entropy();
	}


	ind = 0;
	for (tilelist::const_iterator it = t1.begin(); it != t1.end(); ++it, ind++) {
		uint32_t ind2 = 0;
		for (tilelist::const_iterator it2 = t2.begin(); it2 != t2.end(); ++it2, ind2++) {
			model j(back);
			
			j.add(*it);
			j.add(*it2);
			j.train();
			double je = j.entropy();

			printf("%f ", (ent1[ind] + ent2[ind2] - 2*je) / (be - je));
		}
		printf("\n");
	}
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

	uint32_t K = p.patterns.size();

	doublevector res(K*K);

	ind = 0;
	for (patternlist::iterator it = p.patterns.begin(); it != p.patterns.end(); ++it, ind++) {
		uint32_t ind2 = 0;
		for (patternlist::iterator it2 = p.patterns.begin(); it2 != it; ++it2, ind2++) {
			model j(back);
			
			j.add(**it);
			j.add(**it2);

			j.train();
			//double je = j.entropy();
			res[ind2*K + ind] = res[ind*K + ind2] = (j.kl(*ent[ind]) + j.kl(*ent[ind2])) / (j.kl(back) + 0.000001);
			
			printf("%f %f\n", res[ind2*K + ind], j.test());
			fflush(stdout);
		}
		printf("\n");
	}

	for (uint32_t i = 0; i < ent.size(); i++)
		delete ent[i];

	printf("\nDISTANCE\n");

	for (uint32_t i = 0, k = 0; i < K; i++) {
		for (uint32_t j = 0; j < K; j++, k++) {
			printf("%f ", res[k]);
		}
		printf("\n");
	}
}



int
main(int argc, char ** argv)
{
	patterns p;
	tileset *first = init(argc, argv, p);

	if (first != NULL) {
		if (p.individual)
			patdistance(p, first->dimcnt(), first->transcnt());
		else
			setdistance(p, first->dimcnt(), first->transcnt());
	}

	clear(p);
	return 0;
}

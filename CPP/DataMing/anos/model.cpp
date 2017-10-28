#include "model.h"
#include <math.h>
#include <assert.h>

double
model::support(const tile *t) const
{
	double f = 0;
	for (uint32_t i = 0; i < t->attrs.size(); i++) {
		for (uint32_t j = 0; j < t->trans.size(); j++) {
			f += prob(t->attrs[i], t->trans[j]);
		}
	}
	return f;
}

void
model::exact(const tile *t, uint32_t & zeroes, uint32_t & ones) const
{
	zeroes = ones = 0;

	for (uint32_t i = 0; i < t->attrs.size(); i++) {
		for (uint32_t j = 0; j < t->trans.size(); j++) {
			double q = prob(t->attrs[i], t->trans[j]);
			if (q == 0) zeroes++;
			if (q == 1) ones++;
		}
	}
}


void
model::set(const tile *t, double p) 
{
	for (uint32_t i = 0; i < t->attrs.size(); i++) {
		for (uint32_t j = 0; j < t->trans.size(); j++) {
			prob(t->attrs[i], t->trans[j]) = p;
		}
	}
}

void
model::safeset(const tile *t, double p) 
{
	for (uint32_t i = 0; i < t->attrs.size(); i++) {
		for (uint32_t j = 0; j < t->trans.size(); j++) {
			double & q = prob(t->attrs[i], t->trans[j]);
			if (q == 1 || q == 0) continue;
			q = p;
		}
	}
}

void
model::update(const tile *t, double p) 
{
	for (uint32_t i = 0; i < t->attrs.size(); i++) {
		for (uint32_t j = 0; j < t->trans.size(); j++) {
			double & q = prob(t->attrs[i], t->trans[j]);
			if (q == 1 || q == 0) continue;
			q = p*q/(1 - q*(1 - p));
		}
	}
	//printf("%d %f %d %f\n", c, a / (t->attrs.size() * t->trans.size()), (t->attrs.size() * t->trans.size()), d);
}


void
model::train(double thresh, uint32_t maxiter)
{
	tilelist tiles = m_tiles;

	//printf("Training\n");


	for (uint32_t i = 0; i < maxiter; i++) {

		uint32_t cnt = 0;

		for (tilelist::iterator it = tiles.begin(), itnext; it != tiles.end(); it = itnext) {
			itnext = it; ++itnext;	
			const tile *t = *it;

			//double g = t->freq();
			if (t->exact()) {
				set(t, t->support() > 0);
				tiles.erase(it); // Doesn't need any additional updates
				continue;
			}

			uint32_t ones, zeroes;

			exact(t, zeroes, ones);

			assert(t->count >= ones);
			assert(t->count <= t->area() - zeroes);

			if (t->count == ones) {
				safeset(t, 0);
				tiles.erase(it); // Doesn't need any additional updates
				continue;
			}
			if (t->count == t->area() - zeroes) {
				safeset(t, 1);
				tiles.erase(it); // Doesn't need any additional updates
				continue;
			}

			double f = (support(t) - ones) / (t->area() - zeroes - ones);
			double g = (double(t->support()) - ones) / (t->area() - zeroes - ones);
			// For the sake of numerical stability
			if (f > 1) f = 1; 
			if (g > 1) g = 1;
			if (f < 0) f = 0; 
			if (g < 0) g = 0;

			//printf("%f %f %f %d\n", g, f, (g/f) * ((1 - f)/(1 - g)), cnt);

			if (f == 1 || f == 0) {
				tiles.erase(it); // Doesn't need any additional updates
				continue;
			}

			update(t, (g/f) * ((1 - f)/(1 - g)));

			cnt++;
		}

		double err = test(tiles);

		//printf("ERR: %f %i  \r", err, i);
		//fflush(stdout);

		if (err <= thresh) return;
	}
}

double
model::entropy() const
{
	double res = 0;

	for (uint32_t i = 0; i < m_probs.size(); i++) {
		if (m_probs[i] > 0) 
			res += m_probs[i] * log(m_probs[i]);
		if (m_probs[i] < 1)
			res += (1 - m_probs[i]) * log(1 - m_probs[i]);
	}
		
	return -res;
}

double
model::kl(const model & m) const
{
	assert(m_probs.size() == m.m_probs.size());
	double res = 0;

	for (uint32_t i = 0; i < m_probs.size(); i++) {
		if (m_probs[i] > 0 && m.m_probs[i] > 0) 
			res += m_probs[i] * log(m_probs[i] / m.m_probs[i]);
		if (m_probs[i] < 1 && m.m_probs[i] < 1)
			res += (1 - m_probs[i]) * log((1 - m_probs[i])/(1 - m.m_probs[i]));
	}
		
	return res;
}

void
model::print() const
{
	for (uint32_t j = 0; j < m_transcnt; j++) {
		for (uint32_t i = 0; i < m_attrcnt; i++) {
			printf("%f ", prob(i, j));
		}
		printf("\n");
	}
}


double
model::test(const tilelist & tiles) const
{
	double err = 0;
	for (tilelist::const_iterator it = tiles.begin(); it != tiles.end(); ++it) {
		const tile *t = *it;

		double g = t->freq();
		double f = freq(t);
		double m = f > g ? f : g;

		if (err < fabs(f - g) / m) err = fabs(f - g) / m;

	}

	return err;
}

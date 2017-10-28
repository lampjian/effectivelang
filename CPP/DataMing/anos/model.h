#ifndef MODEL_H
#define MODEL_H

#include <stdint.h>
#include <vector>
#include <string>
#include <list>
#include "tile.h"


class model {
	public:
		model(uint32_t transcnt, uint32_t attrcnt) : m_transcnt(transcnt), m_attrcnt(attrcnt), m_probs(transcnt * attrcnt, 0.5) {}
		model(const tileset & t) : m_transcnt(t.transcnt()), m_attrcnt(t.dimcnt()), m_probs(m_transcnt * m_attrcnt, 0.5) {add(t);}

		void add(const tile *t) {m_tiles.push_back(t);}
		void add(const tileset & t) {m_tiles.insert(m_tiles.end(), t.tiles().begin(), t.tiles().end());}

		void train(double thresh = 0.01, uint32_t maxiter = 100000);

		double support(const tile *t) const; 
		double freq(const tile *t) const {return support(t) / t->area();} 

		double kl(const model & m) const;
		double entropy() const;

		void print() const;

		double test() const {return test(m_tiles);}

	protected:
		double prob(uint32_t a, uint32_t t) const {return m_probs[a * m_transcnt + t];}
		double & prob(uint32_t a, uint32_t t) {return m_probs[a * m_transcnt + t];}

		void exact(const tile *t, uint32_t & zeroes, uint32_t & ones) const;

		void safeset(const tile *t, double p);  
		void set(const tile *t, double p);  
		void update(const tile *t, double p);  

		double test(const tilelist & tiles) const;

		uint32_t m_transcnt;
		uint32_t m_attrcnt;
		doublevector m_probs;

		tilelist m_tiles;
};

#endif

#ifndef TILE_H
#define TILE_H

#include <stdint.h>
#include <stdio.h>

#include <vector>
#include <string>
#include <list>

typedef std::vector<uint32_t> uintvector;
typedef std::vector<double> doublevector;

const double laplace = 0.0;

struct tile {
	uintvector attrs, trans;
	uint32_t count;
	std::string id;

	void print() const;

	//double freq() const {return double(count) / (attrs.size() * trans.size()) * (1 - laplace) + laplace / 2;}
	double freq() const {return double(count) / (attrs.size() * trans.size());}
	uint32_t support() const {return count;}
	uint32_t area() const {return attrs.size() * trans.size();}

	bool exact() const {return count == 0 || count == area();}
};

typedef std::list<const tile *> tilelist;

class tileset {
	public:
		tileset(FILE *f, uint32_t shift);
		~tileset();

		const tilelist & tiles() const {return m_tiles;}

		uint32_t transcnt() const {return m_transcnt;}
		uint32_t dimcnt() const {return m_dimcnt;}

	protected:
		uint32_t m_transcnt;
		uint32_t m_dimcnt;
		tilelist m_tiles;
};


void print(const tilelist & tl);




#endif

#include "tile.h"
#include <assert.h>


tileset::tileset(FILE *f, uint32_t shift)
{
	fscanf(f, "%u%u", &m_transcnt, &m_dimcnt);

	while (true) {
		uint32_t cnt;
		if (fscanf(f, "%u", &cnt) != 1) 
			break;
		tile *t = new tile;
		t->count = cnt;

		fscanf(f, "%u", &cnt);
		if (cnt == 0) {
			t->trans.resize(m_transcnt);
			for (uint32_t i = 0; i < m_transcnt; i++)
				t->trans[i] = i;
		}
		else {
			t->trans.resize(cnt);
			for (uint32_t i = 0; i < cnt; i++) {
				fscanf(f, "%u", &t->trans[i]);
				assert(t->trans[i] < m_transcnt);
			}
		}

		fscanf(f, "%u", &cnt);
		if (cnt == 0) {
			t->attrs.resize(m_dimcnt);
			for (uint32_t i = 0; i < m_dimcnt; i++)
				t->attrs[i] = i;
		}
		else {
			t->attrs.resize(cnt);
			for (uint32_t i = 0; i < cnt; i++) {
				fscanf(f, "%u", &t->attrs[i]);

				assert(t->attrs[i] >= shift);
				t->attrs[i] -= shift;

				assert(t->attrs[i] < m_dimcnt);
			}
		}
		m_tiles.push_back(t);
	}
}

tileset::~tileset()
{
	for (tilelist::iterator it = m_tiles.begin(); it != m_tiles.end(); ++it)
		delete *it;
}

void
tile::print() const
{
	printf("%d\n%ld", count, trans.size());
	for (uint32_t i = 0; i < trans.size(); i++)
		printf(" %d", trans[i]);
	printf("\n%ld", attrs.size());
	for (uint32_t i = 0; i < attrs.size(); i++)
		printf(" %d", attrs[i]);
	printf("\n");
}

void
print(const tilelist & tl)
{
	for (tilelist::const_iterator it = tl.begin(); it != tl.end(); ++it)
		(*it)->print();
}


TIVASRCS = model.cpp tiva.cpp tile.cpp
TIVAOBJS = $(TIVASRCS:.cpp=.o)

TIRASRCS = model.cpp tira.cpp tile.cpp
TIRAOBJS = $(TIRASRCS:.cpp=.o)

TIRESRCS = model.cpp tire.cpp tile.cpp
TIREOBJS = $(TIRESRCS:.cpp=.o)



CC = g++
LDFLAGS= -lm -O3 -fopenmp  
CFLAGS= -g -O3 -Wall -Wextra -fopenmp #-Werror

all : tiva tira tire

tiva: $(TIVAOBJS)
	$(CC) $(LDFLAGS) -o $@ $(TIVAOBJS)

tira: $(TIRAOBJS)
	$(CC) $(LDFLAGS) -o $@ $(TIRAOBJS)

tire: $(TIREOBJS)
	$(CC) $(LDFLAGS) -o $@ $(TIREOBJS)



%.o : %.cpp
	 $(CC) $(CFLAGS) -c $*.cpp

clean:
	-rm *.o tiva tira tire

zip:
	zip tiva.zip *.cpp *.h Makefile readme.txt

depend:
	makedepend -Y -- $(CFLAGS) -- $(TIVASRCS) $(TIRASRCS) $(TIRESRCS)
# DO NOT DELETE

model.o: model.h tile.h
tiva.o: model.h tile.h
tile.o: tile.h
model.o: model.h tile.h
tira.o: model.h tile.h
tile.o: tile.h
model.o: model.h tile.h
tire.o: model.h tile.h
tile.o: tile.h

objects = ruletest.o Item.o AprioriRules.o
Cpp = g++
flags = -O6 -Wall

rules : $(objects) 
	$(Cpp) $(flags) $(objects) -o rules

ruletest.o : ruletest.cpp Item.h AprioriRules.h
	$(Cpp) -c $(flags) ruletest.cpp

Item.o : Item.cpp Item.h
	$(Cpp) -c $(flags) Item.cpp

AprioriRules.o : AprioriRules.cpp AprioriRules.h Item.h
	$(Cpp) -c $(flags) AprioriRules.cpp

clean :
	rm -f $(objects) rules

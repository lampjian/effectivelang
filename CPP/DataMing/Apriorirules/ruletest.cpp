/*----------------------------------------------------------------------
  File     : aprioritest.cpp
  Contents : apriori algorithm for finding association rules
  Author   : Bart Goethals
  Update   : 16/04/2003
----------------------------------------------------------------------*/

#include <stdio.h>
// atof function lib
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <set>
#include <vector>
#include <fstream>
using namespace std;
#include "Item.h"
#include "AprioriRules.h"

int main(int argc, char *argv[])
{
  cout << "Apriori association rule mining implementation" << endl;
  cout << "by Bart Goethals, 2000-2003" << endl;
  cout << "http://www.cs.helsinki.fi/u/goethals/" << endl << endl;
  
  if(argc < 3) {
    cerr << "usage: " << argv[0] << " setsfile minconf [output]" << endl;
  }
  else {
    clock_t start = clock();
    AprioriRules r;
    r.setVerbose();
    r.setData(argv[1]);
    r.setMinConf(atof(argv[2]));
//    r.setMaxHead(1);
    if(argc==4) r.setOutputRules(argv[3]);

    start = clock();
    cout << "generating rules\n" << flush;
    int rules = r.generateRules();
    cout << rules << "\t[" << (clock()-start)/double(CLOCKS_PER_SEC) << "s]" << endl;
    if(argc==4) cout << "Written to " << argv[3] << endl;
  }

  return 0;
}


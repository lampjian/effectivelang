/*----------------------------------------------------------------------
  File     : AprioriRules.cpp
  Contents : apriori algorithm for finding association rules
  Author   : Bart Goethals
  Update   : 16/04/2003
----------------------------------------------------------------------*/

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <set>
#include <vector>
#include <time.h>
using namespace std;
#include "Item.h"
#include "AprioriRules.h"

AprioriRules::AprioriRules()
{
  data=0;
  minconf=0;
  maxhead=0;
  trie = new Item(0);
  verbose = false;
}

AprioriRules::~AprioriRules()
{
  if(data) fclose(data);
  if(trie) {
    trie->deleteChildren();
    delete trie;
  }
}

void AprioriRules::setData(char *fn)
{
  data = fopen(fn,"rt");
}

int AprioriRules::setOutputRules(char *fn)
{
  rulesout.open(fn);
  if(!rulesout.is_open()) {
    cerr << "error: could not open " << fn << endl;
    return -1;
  }
  return 0;
}

Itemset *AprioriRules::getNextSet()
{
  Itemset *t;
  vector<int> list;
  char c;

  do {
    int item=0, pos=0;
    c = getc(data);
    while((c >= '0') && (c <= '9')) {
      item *=10;
      item += int(c)-int('0');
      c = getc(data);
      pos++;
    }
    if(pos) list.push_back(item);
  }while(c != '\n' && !feof(data));
  
  if(feof(data)) return 0;

  int size = list.size() - 1;
  if(size>=0) {
    t = new Itemset(size);
    t->support = list[size];
    for(int i=0; i<size; i++) t->t[i] = list[i];
    return t;
  }
  else return getNextSet();
}

int AprioriRules::generateRules()
{
  int size=0;
  clock_t start;
	
  // Read all frequent itemsets
  if(verbose) cout << "reading frequent itemsets" << flush;
  start = clock();
  while(Itemset *t = getNextSet()) {
    set<Item>::iterator it;
    set<Item>* items = trie->makeChildren();
		
    for(int depth=0;depth < t->length; depth++) {
      it = items->find(Item(t->t[depth]));
      if(it == items->end()) it = items->insert(Item(t->t[depth])).first;
      items = it->makeChildren();
    }
    if(t->length) it->Increment(t->support);
    else trie->Increment(t->support);
		
    size = (t->length>size? t->length : size);
    delete t;
  }
  if(verbose) cout << "[" << (clock()-start)/double(CLOCKS_PER_SEC) << "s]" << endl << flush;
	
  // generate rules
  if(verbose) cout << "generating rules" << flush;
  int *iset = new int[size];
  int added = generateRules(trie->getChildren(), iset, 1);
  delete [] iset;
  if(verbose) cout << "[" << (clock()-start)/double(CLOCKS_PER_SEC) << "s]" << endl << flush;

  return added;
}

int AprioriRules::generateRules(set<Item> *current, int *iset, int depth)
{
  if(current==0) return 0;
  int added = 0;
	
  for(set<Item>::iterator runner = current->begin(); runner!= current->end(); runner++) {
		
    iset[depth-1] = runner->getId();
    if(depth > 1) {
      int *tmp = new int[depth];
      added += processSet(trie->getChildren(), depth, iset, runner->getSupport(), tmp, 0,1);
      delete [] tmp;
    }
		
    added += generateRules(runner->getChildren(), iset, depth+1);
  }
	
  return added;
}

int AprioriRules::processSet(set<Item> *items, int sl, int *iset, int sup, int *head, int spos, int depth)
{
  int loper = spos;
  set<Item>::iterator runner, it;
  int added=0,i,j,k;
	
  spos = sl;
  while(--spos >= loper) {
    head[depth-1] = iset[spos];
    runner = items->find(Item(iset[spos]));

    // find body and its support
    set<Item> *tmp = trie->getChildren();
    int *body = new int[sl-depth];
    for(i=j=k=0; i<sl; i++)	{
      if(j<depth && iset[i]==head[j]) j++;
      else {
	it = tmp->find(Item(iset[i]));
	tmp = it->getChildren();
	body[k++] = iset[i];
      }
    }
//    float intr = (float(sup)*float(trie->getSupport()))/(float(runner->getSupport())*float(it->getSupport()));
    float conf = float(sup)/float(it->getSupport());
		
    if(conf>=minconf) {
      for(i=0; i<sl-depth; i++) rulesout << body[i] << " ";
      rulesout << "=> ";
      for(i=0; i<depth; i++) rulesout << head[i] << " ";
      rulesout << "(" << sup << ", " << conf << ")" << endl;
//      rulesout << "(" << sup << ", " << conf << ", " << intr << ")" << endl;
      added++;
    }
    delete [] body;

    if(conf>=minconf && depth<sl-1) {
      if(maxhead) {
	if(depth<maxhead) added += processSet(runner->getChildren(), sl, iset, sup, head, spos+1, depth+1);
      }
      else added += processSet(runner->getChildren(), sl, iset, sup, head, spos+1, depth+1);
    }
  }
	
  return added;
}


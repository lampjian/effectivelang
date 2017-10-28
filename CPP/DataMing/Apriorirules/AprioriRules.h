
class Itemset
{
 public:
  Itemset(int l) : length(l) {t = new int[l];}
  Itemset(const Itemset &is) : length(is.length), support(is.support) 
    {
      t = new int[length];
      for(int i=0;i<length;i++) t[i] = is.t[i];
    }

  ~Itemset(){delete [] t;}
	
  int length;
  int *t;
  int support;
};

class AprioriRules
{
 public:

  AprioriRules();
  ~AprioriRules();

  void setData(char *fn);
  int setOutputRules(char *fn);
  void setMinConf(float mc){minconf=mc;}
  int generateRules();
  void setMaxHead(int m){maxhead=m;}
  void setVerbose(){verbose=true;}
	
 private:		

  Itemset *getNextSet();
  int generateRules(set<Item> *current, int *iset, int depth);
  int processSet(set<Item> *items, int sl, int *iset, int sup, int *head, int spos, int depth);

  Item *trie;
  float minconf;
  int maxhead;
  ofstream rulesout;
  FILE *data;
  bool verbose;
};


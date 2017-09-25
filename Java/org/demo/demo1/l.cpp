#include <iostream>
#include <cmath>

using namespace std;

int minWired(int num, int *glow, int * distance)
{
	int mindis[num] = {0},ind=0,wisedist=0,total=0;
	bool init = false;

	cout << "This is a test:"<<endl;
	for(int x = 0; x<num;x++)
	{
		cout <<glow[x];
		cout <<" "<<distance[x]<<endl;
	}
	cout <<"Print end"<<endl;

	for(int i=0; i<num; i++) {
		if(glow[i]==0) {
			init = false;
			for(int j=0;j<num; j++) {
				if(i!=j)
				{
					cout <<"i="<<i<<" j="<<j<<endl;
					if(glow[j]==1) {
						wisedist=abs(distance[j]-distance[i]);
						cout << "i:"<<i<<"j:"<<j<<endl;
						cout << "W:"<<wisedist<<endl;
						cout <<"distance[j]:"<<distance[j]<<"distance[i]"<<distance[i]<<endl;
						if(init) {
							mindis[ind] = mindis[ind]<wisedist?mindis[ind]:wisedist;
						} else {
							mindis[ind] = wisedist;
							init = true;
						}
					}
				}
			}
			glow[i] = 1;
			ind++;
		}
	}
	for(int k=0; k< num; k++){
		cout << mindis[k]<<endl;
		total += mindis[k];
	}
	return total;
}

int main()
{
	int n = 3;
	int gs[] = {1,0,1};
	int dist[] = {1,5,6};
	cout << minWired(n,gs,dist)<<endl;
	return 0;
}


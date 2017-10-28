#include<iostream>
using namespace std;
void jisuan(int i,int j)
{
	int a,b;
	for(a=i;a<=i+8;a++)
	{
		for(b=j;b<=a;b++)
		{
			cout<<b<<"*"<<a<<"="<<a*b<<"\t";
		}
		cout<<"\n";
	}
}

int main()
{
	jisuan(11,11);
	jisuan(21,21);
	jisuan(31,31);
	jisuan(41,41);
	jisuan(51,51);
	jisuan(61,61);
	jisuan(71,71);
	jisuan(81,81);
	jisuan(91,91);
}

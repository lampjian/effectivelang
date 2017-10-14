#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
void fun(int *p1,int *p2,int *t)
{
	t = (int *)malloc(sizeof(int));
	*t=*p1+*(p2++);
}

int main()
{
	int a[2] = {1,2};
	int b[2]={10,20};
	int *t = a;
	cout << *t <<endl;
	cout <<"size of t:"<<sizeof(t)<<endl;
	cout <<"size of a:"<<sizeof(a)<<endl;
	fun(a,b,t);
	cout << *t <<endl;
	cout << *a <<endl;
	cout <<"size of t:"<<sizeof(t)<<endl;
	cout <<"size of a:"<<sizeof(a)<<endl;

	// no needed initialize 0, otherwise may
	int *c = new int[5];
	cout <<"size of c:"<<sizeof(c)<<endl;
	// memset(c,0,5*sizeof(int)); dynamic mem initial values are 0.
	for(int i=0;i<5;i++)
		cout << "c["<<i<<"]:"<<c[i]<<endl;
	delete []c;

	return 0;
}

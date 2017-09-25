#include <iostream>
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
fun(a,b,t);
cout << *t <<endl;
return 0;
}

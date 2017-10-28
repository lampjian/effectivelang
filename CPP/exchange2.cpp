#include <cstdio>

//call by reference(only C++)
void exch(int &a,int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

int main(void)
{
	int x=10,y=20;
	printf("x=%d,y=%d.\n",x,y);
	exch(x,y);
	printf("After swap...\n");
	printf("x=%d,y=%d.\n",x,y);
}

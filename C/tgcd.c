#include <stdio.h>

int GCD(int a,int b)
{

	return b==0?a:GCD(b,a%b);
}

void main()
{
	printf("%d\n",GCD(2,4));
}

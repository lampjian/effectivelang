#include <stdio.h>
#define swap(A,B) {int temp=A;A=B;B=temp;}

void exch(int *a,int *b)
{
	// math calculate
	*a = *a+*b;
	*b = *a-*b;
	*a = *a-*b;
}

void exch2(int *a,int *b)
{
	// bit method 1 
	*a = *a^*b;
	*b = *a^*b;
	*a = *a^*b;
}

void exch3(int *a,int *b)
{
	// bit method 2
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

void exch4(int *a,int *b)
{
	// bit method 3
	*a ^= *b ^= *a ^= *b;
}

void exch5(int *a, int *b)
{
	// algebra
	*b = *a + *b -(*a=*b);
	// a = a + b -(b=a);
}

void main(void)
{
	int x=10,y=20;
	printf("x=%d,y=%d.\n",x,y);
	exch(&x,&y);
	printf("After swap...\n");
	printf("x=%d,y=%d.\n",x,y);
	exch2(&x,&y);
	printf("x=%d,y=%d.\n",x,y);
	exch3(&x,&y);
	printf("x=%d,y=%d.\n",x,y);
	exch4(&x,&y);
	printf("x=%d,y=%d.\n",x,y);
	exch5(&x,&y);
	printf("x=%d,y=%d.\n",x,y);
	swap(x,y);
	printf("x=%d,y=%d.\n",x,y);
}

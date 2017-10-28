#include <stdio.h>
#define FALSE 0
#define TRUE 1

void swap(int *a,int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void bubbleSort(int *a, int n)
{
	int *p = a;
	short exchange = FALSE;
	for(int i=0; i<n;i++)
	{
		for(int j=n-1;j>i;j--)
		{
			//asc升序排序, 左->右 
			if(a[j]<a[j-1])
			{
				swap(&a[j], &a[j-1]);
				exchange = TRUE;
			}
		}
		if(! exchange) return;
	}
}

void main(void)
{
	// int x[] = {3,2,0,88,9};
	int x[] = {3,6,9,88,100,2,0};
	int len = sizeof(x)/sizeof(x[0]);
	bubbleSort(x,len);
	for(int i=0;i<len;i++)
		printf("value of x[%d]:%i.\n",i,x[i]);
}

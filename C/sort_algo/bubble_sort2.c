#include <stdio.h>
#define FALSE 0
#define TRUE 1

void swap2(int *a,int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void bubbleSort(int *a, int n)
{
	short exchange = FALSE;
	for(int i=0; i<n-1; i++) // n-1 compare times
	{
		for(int j=0; j<n-i-1; j++) // from 0 to n-1-i
		{
			//asc升序排序, 左->右 
			if(a[j]>a[j+1])
			{
				// swap2(&a[j], &a[j+1]);
				int tp = a[j];
				a[j] = a[j+1];
				a[j+1] = tp;

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
	// printf("Length of x is:%d.\n",len);
	bubbleSort(x,len);
	for(int i=0;i<len;i++)
	{
		printf("value of x[%d]:%i.\n",i,x[i]);
	}
}

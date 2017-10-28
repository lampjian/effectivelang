#include <stdio.h>

void main(void)
{
	int i=1,j=1;
	for(;i<10;i++)
	{
		for(j=1;j<=i;j++)
		{
			printf("%d*%d=%i ",i,j,i*j);
		}
		printf("\n");
	}
	printf("\n");

	i=1;
	for(;i<10;i++)
	{
		for(j=1;j<=i;j++)
		{
			printf("%d*%d=%i ",j,i,i*j);
		}
		printf("\n");
	}
}

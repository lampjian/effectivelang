#include <stdio.h>
void main(void)
{
	int i=1,j=1;
	for(;i<20;i++)
	{
		for(j=i;j<20;j++)
		{
			if(j==19)
			{
				printf("%d*%d=%i\n",i,j,i*j);
			} else {
				printf("%d*%d=%i ",i,j,i*j);
			}
		}
	}
}


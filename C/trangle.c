#include<stdio.h>  

void printf_trangle(int n);  
int main()  
{  
	int n;  
	printf("input trangle lengh\n");  
	scanf("%d",&n);  
	printf_trangle(n);  
	return 0;  
}  


void printf_trangle(int n)  
{  
	int i,j;  
	for(i=1;i<=n;i++)  
	{  
		for(j=0;j<n-i;j++)  
			printf(" ");  
		for(j=0;j<2*i-1;j++)  
			printf("*");  
		printf("\n");  
	}  
}  

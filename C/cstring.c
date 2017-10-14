#include<stdio.h>
int main(void)
{
	// char str[50]={};
	// char str[50]={""};
	// char str[50]={0};
	// char str[50]={'\0'};
	char str[50];
	int l = 0;
	while(l<50) {
		printf("Before the %i\'th char is:%c.\n",l,str[l]);
		//str[l]=0;
		//str[l]='\0';
		printf("After the %i\'th char is:%c.\n",l,str[l]);
		l++;
	}
	printf("Please input a string, len<51.\n");
	scanf("%[^\n]",str);/*scanf("%s",string);不能接收空格符*/
	printf("%s\n",str);
	return 0;
}


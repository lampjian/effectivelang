#include <stdio.h>

void main()
{
	char str[128];
	scanf("%[^\n]", str);
	printf("This is the string:%s.\n", str);
	getchar(); // get a 
}

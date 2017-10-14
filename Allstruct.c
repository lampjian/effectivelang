#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int len;
	char str[0];
} vla;

int main(void)
{
	vla *va = (vla*)malloc(sizeof(vla)*10);
	memset(va->str,'a',10);
	va->len = 10;
	printf("the content of va is:%s\n",va->str);
	printf("the content of va[0] is:%c\n",va->str[0]);
	
	free(va);
	vla v2 = {0};
	// v2.str[0] = 'b';
	printf("The content of va[0] is:%c\n",v2.str[0]);

	return 0;
}


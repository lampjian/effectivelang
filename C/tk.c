#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char s[] = "root:x:1:0:/root:/bin/bash";
	char *token;
	token = strtok(s,":");
	printf("%s\n", token);

	while(token=strtok(NULL,":"))
	{
		printf("%s\n", token);
	}
	
	exit(-1);
	return 0;
}


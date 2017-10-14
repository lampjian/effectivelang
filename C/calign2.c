#include <stdio.h>

typedef struct Test
{
	char a;
	short b;
} Test;

#pragma pack(1)
struct Test2
{
	char a2;
	short b2;
	float c2;
	char d2;
};
#pragma pack()


void main()
{
	Test a={'x',2,};
	struct Test2 b = {'m',1,5,'n'};
	printf("Size of a is:%d.\n",sizeof(a));
	printf("Size of b is:%d.\n",sizeof(b));
	printf("Size of b.char is:%d.\n",sizeof(b.a2));
	printf("Size of b.short is:%d.\n",sizeof(b.b2));
	printf("Size of b.float is:%d.\n",sizeof(b.c2));

	int x=3;
	char s[] = "Hello.";
	printf("x+s:%c, ",x+s[2]);
	printf("s+x:%d, ",s[2]+x);
	printf("x+s[0]:%c.\n",x+s[0]);

}


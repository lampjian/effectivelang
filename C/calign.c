#include <stdio.h>

typedef struct Test
{
	char a;
	short b;
	float c;
	char d;
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
	Test a={'x',2,3,'y'};
	struct Test2 b = {'m',1,5,'n'};
	printf("Size of a is:%d.\n",sizeof(a));
	printf("Size of b is:%d.\n",sizeof(b));
	printf("Size of a.char is:%d.\n",sizeof(a.a));
	printf("Size of a.short is:%d.\n",sizeof(a.b));
	printf("Size of a.float is:%d.\n",sizeof(a.c));
}


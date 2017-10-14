#include <stdio.h>

int main(void)
{

	int x = -2;
	x <<= 27;
	printf("Your x value is:%d.\n",x);
	printf("The value of data:%d.\n",x>>27);
	float a=1.3;
	double b = 2.2;
	printf("The value of a:%f.\n",a);
	printf("The value of b:%lf.\n",b);
	if(a==(float)1.3) printf("a == 1.3\n");
	else
		printf("not equal\n");
	if(b==2.2) printf("b == 2.2\n");
	else
		printf("not equal\n");

	struct node {
		int data;
		char ch;
	}t;
	printf("t.data is:%d, t.ch is:%c.\n",t.data,t.ch);

	return 0;
}


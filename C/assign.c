#include <stdio.h>

void main()
{
    short isPositive(short n);
	int a = 0;
	a = 10;
	a += a -= a *= a;
	printf("The value of a:%d.\n", a);

	a += (a += 5);
	printf("The value of a:%d.\n", a);

	a = (a += 5);
	printf("The value of a:%d.\n", a);

	a += a /= a *= a;
	printf("The value of a:%d.\n", a);
	int c,d,e=1;
	c = d = e;
	printf("The value of c:%d.\n", c);

	printf("The boolean value of 1==2:%i.\n", (1==2));
	printf("The boolean value of 1<=2:%i.\n", (1<=2));

	short k=0;
	short x = isPositive(k);
	printf("The value of x:%i.\n", x);

	printf("Press enter to continue...");
	getchar(); // get a 
}


short isPositive(short n)
{
	if(n<0)
	{
		return 0;
	}
	else if(n>0)
	{
		return 1;
	}
}

#include <stdio.h>

void Sequence(int n) {
	while(n != 1) {
		printf("%i\n", n);
		if(n%2 == 0) { // n is even
			n = n/2;
		}
		else { // n is odd
			n = n*3 + 1;
		}
		if (n>1e+7) {
			break;
		}
	}
}

void main()
{
	int x;
	printf("Your first num:");
	scanf("%d",&x);
	Sequence(x);
}


#include <iostream>
using namespace std;

char * reverse(char*);

int main(void)
{
	char test[] = "This is a test.";
	cout << reverse(test) << endl;

}

char* reverse(char *s)
{
	char *p = s;

	char *q =s;
	while(*q++);
	q -= 2;

	while(q>p)
	{
		int temp = *p;
		*p++ = *q;
		*q-- = temp;
	}

	return s;
}


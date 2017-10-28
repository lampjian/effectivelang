#include <iostream>
using namespace std;

int main(void)
{
	char *reverse(char*);
	char hello[] = "Hello, there. OK.";
	char *p = reverse(hello);
	cout << p << endl;
	delete [] p;
}

char* reverse(char *s)
{
	char *q = s;
	while(*q++);
	q--;
	char * p = new char[sizeof(char)*(q-s+1)];
	char * r =p;

	//reverse
	while(q>=s)
	{
		*p++ = *--q;
	}
	*p = '\0';
	return r;
}


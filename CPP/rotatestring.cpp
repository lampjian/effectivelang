#include <iostream>
#include <cstring>

using namespace std;

void reverseString(char *s, int from, int to)
{
	while(from<to)
	{
		char t = s[from];
		s[from++] = s[to];
		s[to--] = t;
	}
}

void rotateString(char *s, int n, int m)
{
	m %= n;
	reverseString(s,0,m-1);
	reverseString(s,m,n-1);
	reverseString(s,0,n-1);
}

int main()
{
	char str[] = "Hello, world.";
	cout << "String:"<<str<<endl;

	cout <<"size of str:"<<sizeof(str)<<endl;
	cout <<"len of str:"<<strlen(str)<<endl;

	rotateString(str,13,2);
	cout <<"Rotated string:"<<str<<endl;

	return 0;
}

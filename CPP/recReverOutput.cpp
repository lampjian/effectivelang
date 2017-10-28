#include <iostream>
#include <cstdio>
#include <cctype>

using namespace std;

void reverseOutput()
{
	char ch = getchar();
	if(ch != '\n')
	{
		reverseOutput();
		if(!ispunct(ch))
		{
			cout << ch << " ";
		}
	}
}

int main(void)
{
	reverseOutput();
	cout << endl;
	// another reverse output method is print from strlen(s)-1 to 0,
	// or sizeof(s)-2 to 0, notice the punctuation if neccessary. 
	return 0;
}


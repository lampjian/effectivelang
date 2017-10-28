#include <iostream>

using namespace std;

int main(void)
{
	void recurReverse(char *s,int left,int right);
	char test[] = "This is a test array string.";
	recurReverse(test,0,sizeof(test)-2);
	cout << test << endl;
	char * reverse(char *s,int left,int right);
	cout << reverse(test,0,sizeof(test)-2) << endl;
	char * inplaceReverse(char*);
	cout << inplaceReverse(test) << endl;
}

void recurReverse(char *s,int left,int right)
{
	if(left >= right)
	{
		return;
	}
	char t = s[left];
	s[left] = s[right];
	s[right] = t;
	
	recurReverse(s,left+1,right-1);
}

char * reverse(char *s,int left,int right)
{
	while(left<right){
		char ch = s[left];
		s[left++] = s[right];
		s[right--] = ch;
	}
	return s;
}

// the same type values only
char * inplaceReverse(char *s)
{
	char *r = s;
	
	char *p = s;
	while(*p++);
	p -= 2;
	
	while(s<p)
	{
		*p ^= *s;
		*s ^= *p;
		*p-- ^= *s++;
	}
	return r;
}

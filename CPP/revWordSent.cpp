#include <iostream>
#include <cstdlib>
#include <cctype>
using namespace std;

int main(void)
{
	void reverSentence(char *s);
	void reverWord(char *l,char *r);

	char test[] = "Reverse each word of the sentence.";
	cout << "Origin sentence:" << test << endl;
	reverSentence(test);
	cout << "After reverse word of sent:" << test << endl;
	/*
	for(int i=0;i<sizeof(test)-1;i++) {
		cout << test[i] << endl;
	}
	*/
}

void reverWord(char *l,char *r)
{
	while(l<r)
	{
		char t = *l;
		*l++ = *r;
		*r-- = t;
	}
}

void reverSentence(char *s)
{
	char *p = s, *l = s,*t;
	while(*p == ' ' || !(isalpha(*p) || isdigit(*p)))
	{
	    if(*p != '\0' && p !=NULL)
		{
		    p++; // skip spaces and punctuation
		} else {
			exit(-100);
		}
	}
	while(*p != '\0')
	{
		if(*p == ' ')
		{
			reverWord(l,p-1);
			while(*p == ' ' || (!isalpha(*p) && !isdigit(*p))) 
			{
			    if(*p != '\0')
			    {
			    	p++;
				} else {
					break;
				}
			}
			l = p;
		} else {
			p++;
		}
	}
	p--; // back to the end of string before the end sign
	// skip spaces and punctuation
	while(*p == ' ' || (!isalpha(*p) && !isdigit(*p))) 
	{
		if(p>l)
		{
			p--;
		} else {
			break;
		}
	}
	t = p;
	//reverse last world
	reverWord(l,p);
	// reverse the sentence
	reverWord(s,t);
}

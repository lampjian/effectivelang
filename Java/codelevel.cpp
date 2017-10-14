/*
   level 0: <8/same as name or verse/one class
   level 1: >=8 && two classes(digit+little chars or digit+upper)
   level 2: >=8 && two classes(not digit+lower && digit+upper)
   level 3: >=8 && threee classes over
   four classes:
digit : 0 - 9
lower chars: a-z
upper chars: A-Z
special chars: othres
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string name = "",pass="";
    while(true)
	{
		cin >> name;
	    cin >> pass;
		cout << "Name:"<<name<<",Pass:"<<pass<<endl;
		string rname(name.rbegin(),name.rend());
		cout <<"rname:"<<rname<<endl;
        bool digit = false, lower=false,upper=false,othre=false;
		for(int i=0; i<pass.length();i++)
		{
			if('0'<=pass[i] || '9'>=pass[i])
				digit = true;
			else if('a'<=pass[i] || 'z'>=pass[i])
					lower = true;
			else if('A'<=pass[i] || 'Z'>=pass[i])
				upper = true;
			else
				other = true;
		}

		int level = 0;
		if(pass.length()<8 || (name == pass || rname == pass) || ()
				cout << 0<<endl;


	}
	return 0;
}


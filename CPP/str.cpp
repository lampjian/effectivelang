#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

int main()
{
	string str("123456789");
	reverse(str.begin(), str.end());
	cout << str << endl;
	cout << "\u0033 \u0065 \u62a5"<< endl;
	cout << "\u5e7f\u4e1c\u000a\u77e5\u4e4e\u000a"<<endl;

	fstream uf("test.txt", ifstream::in);
	char buffer[100] = {0};
	if(uf.is_open())
		cout <<"Fist file openend."<<endl;
	while(uf.eof() != 0)
	{
		uf.getline(buffer,100);
		cout << buffer <<endl;
	}
	uf.close();
	cout << "Another way to read."<<endl;
	ifstream iuf("test.txt", ifstream::in);
	string line;
	while(iuf.good())
	{
		getline(iuf, line);
		cout << line <<endl;
		printf(line.c_str());
	}
	iuf.close();

	string s("\u5e7f\u4e1c");
	cout << s <<endl;

}

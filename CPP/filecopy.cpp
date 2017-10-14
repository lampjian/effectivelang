#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream fin("out.txt",ios::binary);
	if(!fin)
	{
		cout << "File opened error." << endl;
		return 0;
	}
	ofstream fout("out2.txt", ios::binary);
	char buf[1024]={'\0'};
	while(!fin.eof())
	{
		fin.read(buf,1024);
		fout.write(buf,1024);
	}
	fin.close();
	fout.close();
	cout << "Copy over." << endl;
	return 0;
}

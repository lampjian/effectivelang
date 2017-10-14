#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ofstream out("out.txt");
	if(out.is_open())
	{
		out << "This is a line.\n";
		out << "This is another line.\n";
		out.close();
	}

	fstream f("out.txt",ios::out|ios::app);
	f<<1234<<' '<<3.14<<'A'<<"How are you\n"; //写入数据
	f.close();

	f.open("out.txt",ios::in);
	int i;
	double d;
	char c;
	char s[20];
	char buffer[25]={};
	f.getline(buffer,25);
	f.getline(buffer,25);

	f>>i>>d>>c;               //读取数据
	f.getline(s,20);

	cout<<i<<endl;             //显示各数据
	cout<<d<<endl;
	cout<<c<<endl;
	cout<<s<<endl;
	f.close();

	return 0;
}


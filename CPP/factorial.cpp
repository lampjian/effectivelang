#include <iostream>
#include <string>

using namespace std;

long fact(int);

int main()
{
	int n;
	long fn=0;
	char c[10] = "";
	string s = "";
	cout <<"size of s:"<<sizeof(s)<<endl;
	cout <<"s:"<<s<<endl;
	cout <<"s:"<<&s<<endl;
	cout <<"c[2]:"<<c[2]<<endl;
	cout <<"c[2]:"<<(short)c[2]<<endl;
	cout << "No init n:"<<n<<endl;
	n = 0;
	cout <<"Please input an integer:";
	cin >> n;
	if(n>=0 && n<13)
	{
		cout << "Number:"<< n <<endl;
		fn = fact(n);
		cout << "Fact of "<<n<<" is:"<<fn<<endl;
	}
	return 0;
}

long fact(int x)
{
	if(x==0 || x==1) return 1;
	return x*fact(x-1);
}

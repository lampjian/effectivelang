#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s,m,paw="";
	int a,x,k,t,y=0;
	cout <<"请输入特征码：";
	cin >>s;
	cout << "请输入校正码：";
	cin >> m;
	x = m.size();

	while(y<x)
	{
		//paw.append(1,s[y]).append(1,m[y]);
		string st;
		cout << "st is :"<<sizeof(st)<<"--"<<hex<<&st<<endl;
		cout <<"length of st is:"<<st.size()<<endl;
		st += s[y];
		st += m[y];
		paw = st;
		cout <<"s["<<y<<"] is:"<<s[y]<<" m["<<y<<"] is:"<<m[y]<<" paw:"<<paw<<endl;
		if(y<2) {
			cout <<"paw="<<paw[y]<<endl;
		}
		y++;
	}
	/*
	cout <<"0:"<<(short)'0'<<endl;
	cout <<"1:"<<(short)'1'<<endl;
	cout <<"0+0:"<<'0'+'0'<<endl;
	cout <<"1+1:"<<'1'+'1'<<endl;
	cout <<"0+1:"<<'0'+'1'<<endl;
	*/
	string s01="Hello";
	string s02="Hello";
	string s03="  world  s";
	string ss = s02+s03;
	s01[0]='h';
	cout << "s:"<<ss<<" s01==s02:"<<(s01==s02)<<" s01:"<<s01<<endl;
	return 0;
}


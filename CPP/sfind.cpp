#include<iostream>
#include <string>
#include <cstdio>

using namespace std;

const string gs = "Hello, global strings.";

void test() {
	cout << "Amazing global string:"<<gs<<endl;
}

int main() {
	test();
	string str1,str2;
	cout<<"请输入第一个字符串"<<endl;
	cin>>str1;
	cout<<"请输入子串"<<endl;
	cin>>str2;

	int weizhi = 0;
	int count = 0;
	while (1) {
		weizhi = str1.find(str2,weizhi);
		weizhi++;
		if (0 == weizhi) {
			break;
		}
		else {
			count++;
			cout<<"子串出现的位置是："<<weizhi<<endl;
		}
	}

	cout<<"子串出现的次数是："<<count<<endl;
	getchar();
	string st("12345asdf");
	string a = st.substr(0,5);
	cout << "sub 0 5 of st:"<<a<<endl;
	char const * ch1;
	char c[] = "Hello";
	ch1 = c;
	char *const ch2 =c ;
	return 0;
}


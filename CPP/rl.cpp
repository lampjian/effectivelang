#include <iostream>
#include <string>

using namespace std;

int main()
{
	cout <<"Please input the queue:";
    string que;
	cin >> que;
	cout << "Your queue is:"<<que<<endl;
	int len = que.length();
	while(que.find("RL",0) != string::npos) {
		len--;
		que = que.substr(0,len);
		cout << "While que:"<<que<<endl;
	}
	cout << "The smallest len:"<<len<<endl;
}



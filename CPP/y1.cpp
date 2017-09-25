#include <iostream>

using namespace std;

int main()
{
	int nrow=0, x = 0;
	cin >> nrow;
	if(nrow>=1 && nrow <= 10)
	{
		while(nrow--)
		{
			cin>>x;
			if(x<1 || x>1e+06)
			{
				cout << x <<endl;
				break;
			}
			cout << 1e+06<<endl;
		}
	}

	return 0;
}

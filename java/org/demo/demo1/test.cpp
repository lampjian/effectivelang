#include <iostream>

using namespace std;

int main()
{
	int arr[3][4] = {1,2,3,4,5,6,7,8,9};
	for(int i=0; i<3; i++)
	{
		int j;
		for(j=0; j<3; j++)
			cout << "[i,j:"<<i<<','<<j<<']'<<arr[i][j]<<',';
		cout << arr[i][j]<<endl;
	}
	//cout << endl;
	//
	for (int l=0;l<5;l++)
	{
		for(int m=0; m<6; m++)
			if(m !=l)
				cout<< "Hello:"<<l<<','<<m<<endl;
	}
	return 0;
}

#include <iostream>

using namespace std;

int main()
{
	// new variables
	int *ptr = new int(10);
	cout << "Add:" << ptr <<endl;
	cout << "Value:" << *ptr <<endl;

	*ptr = 20;
	cout << "Add2:" << ptr <<endl;
	cout << "Value2:" << *ptr <<endl;
	delete ptr;

	//new arr
	int **p = new int* [2];
	for(int i=0; i<2; i++)
		p[i] = new int[10];
	for ( int i=0; i<2; i++)
	{
		for(int j=0; j<10; j++)
		{
			p[i][j] = i+j;
			cout << p[i][j] <<endl;
			cout << *(*(p+i)+j) <<endl;
			cout << *(p[i]+j) <<endl;
		}
	}
	for(int i=0; i<2; i++)
		delete[] p[i];
	delete[] p;
}

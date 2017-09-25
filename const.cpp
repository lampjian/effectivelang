#include <iostream>

using namespace std;

int main()
{
	const int i = 10;
	int *j = (int*)&i;
	*j += 10;
	cout << i << "---" << *j <<endl;

	return 0;
}


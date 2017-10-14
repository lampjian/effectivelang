#include <iostream>
#include <stdint.h>

using namespace std;

int64_t power2BF_I(int n)
{ // n>=0
	int64_t pow = 1;
	while(0<n--)
		pow <<= 1;
	return pow;
}

int main()
{
	int x;
	cin >> x;
	cout << power2BF_I(x) <<endl;
}


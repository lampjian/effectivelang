#include <iostream>

using namespace std;

void bubbleSort(int a[], int n)
{
	bool sorted = false;
	while(!sorted)
	{
		sorted = true;
		for(int i=1; i<n; i++)
			if(a[i-1]>a[i])
			{
				swap(a[i-1],a[i]);
				sorted = false;
			}
		n--;
	}
}

int main(void)
{
	int arr[] = {1, 3, 5, 7, 9, 11};
	cout << "size of arr is:" << sizeof(arr)/sizeof(int)<<endl;
	bubbleSort(arr,sizeof(arr)/sizeof(int));
	cout <<"Finished sorting."<<endl;
	for(int i=0; i<sizeof(arr)/sizeof(int); i++)
		cout <<"arr["<<i<<"] is"<<arr[i]<<endl;
} 

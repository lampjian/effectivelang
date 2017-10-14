#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>

#define size1 5
#define size2 10
#define size3 15

using namespace std;

int main()
{
	// single type variable
	string *s1 = new string("Hello");
	cout << "First string:"<<*s1<<endl;
	delete s1;

	// one dimension arr
	int *arr1 = new int[10];
	// init arr
	memset(arr1,1,2); // new is in heap, not 0 is ok.
	for(int ii=0;ii<10;ii++)
		cout << "arr1["<<ii<<"]:"<<arr1[ii] <<endl;
	// destroy
	delete[] arr1;

	// 2-dimension arr
	int **arr2;
	arr2 = new int* [20];
	for(int i2=0;i2<10;i2++)
	{
		arr2[i2] = new int[5];
		memset(arr2[i2],20,5*sizeof(int));
	}
	//destroy
	for(int i=0; i<10; i++)
		delete[] arr2[i];
	delete[] arr2;


	int *** arr;
	int i,j,k;
	/////////////////// 动态开辟 相当于arr[size1][size2][size3]
	arr = new int**[size1];
	for (i = 0; i < size1; i ++) {
		arr[i] = new int*[size2];
		for (j = 0; j < size2; j ++) {
			arr[i][j] = new int[size3];
		}
	}
	/////////////////// 用for循环初始化
	for (i = 0; i < size1; i ++) {
		for (j = 0; j < size2; j ++) {
			for (k = 0; k < size3; k ++) {
				arr[i][j][k] = i * j * k;
			}
		}
	}
	for (i = 0; i < size1; i ++) {
		for (j = 0; j < size2; j ++) {
			for (k = 0; k < size3; k ++) {
				printf("i*j*k=%d*%d*%d=%d\n",i,j,k,arr[i][j][k]);
			}
		}
	}
	/////////////////// 用memset，如果是静态int arr[][][]的话，直接memset(arr,0,sizeof(arr));数组初始化为0
	for (i = 0; i < size1; i ++) {
		for (j = 0; j < size2; j ++) {
			memset(arr[i][j],-1,sizeof(int) * size3);
		}
	}
	for (i = 0; i < size1; i ++) {
		for (j = 0; j < size2; j ++) {
			for (k = 0; k < size3; k ++) {
				printf("i,j,k=%d,%d,%d=%d\n",i,j,k,arr[i][j][k]);
			}
		}
	}
	///////////////////// 释放内存
	for (i = 0; i < size1; i ++) {
		for (j = 0; j < size2; j ++) {
			delete[] arr[i][j];
		}
		delete[] arr[i];
	}
	delete[] arr;

	return 0;
}

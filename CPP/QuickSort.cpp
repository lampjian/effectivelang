// sortalgo.cpp : Defines the entry point for the console application.
//快速排序（Quicksort）是对冒泡排序的一种改进。
/*
由C. A. R. Hoare在1962年提出。
它的基本思想是：通过一趟排序将要排序的数据分割成独立的两部分，
其中一部分的所有数据都比另外一部分的所有数据都要小，
然后再按此方法对这两部分数据分别进行快速排序，
整个排序过程可以递归进行，以此达到整个数据变成有序序列。
-- 百度百科

划分交换排序，采用分治策略（分治法-Divide-and-ConquerMethod） 分治法
思想：
1. 先从数列中取出一个数作为 基准数pivot
2. 分区过程，将比这个数大的数全放到它的右边，小于或等于它的数全放到它的左边
3. 再对左右区间重复第二步，直到各区间只有一个数
*/

// #include "stdafx.h"
#include <iostream>
#include <limits.h>

int partition(int pc[], int l, int h) {
	int pos = 0, pivot=0, i=l, j=h;
	pivot = pc[l];
	while(i<j)
	{
		// right to left for less than temp
		while(i<j && pc[j]>=pivot)
			j--;
		if(i<j)
		{
		    pc[i] = pc[j];
		    i++;
		}
		// left to right for bigger or equal than temp
		while(i<j && pc[i]<pivot)
			i++;
		if(i<j)
		{
		    pc[j] = pc[i];
		    j--;
		}
	}
	// end when i==j
	pc[i] = pivot;
	return i;
}

void quick_sort(int a[], int low, int high) {
	int i=0;
	if(low<high)
	{
		i = partition(a,low,high);
		quick_sort(a, low, i-1);
		quick_sort(a, i+1, high);
	}
}

/*
int _tmain(int argc, _TCHAR* argv[])
{
	int x[] = {40,33,20,19,3,2,100,13,6,8};

	std::cout << "This is quick sort now:"<<std::endl;
	quick_sort(x,0,9);
	for(int i=0; i<10; i++)
	{
		std::cout<<"x["<<i<<"] is:"<<x[i]<<std::endl;
	}

	return 0;
}

*/
int main(int argc, char* argv[])
{
	int x[] = {40,33,20,19,3,2,100,13,6,8};

	std::cout << "This is quick sort now:"<<std::endl;
	quick_sort(x,0,9);
	for(int i=0; i<10; i++)
	{
		std::cout<<"x["<<i<<"] is:"<<x[i]<<std::endl;
	}

	return 0;
}

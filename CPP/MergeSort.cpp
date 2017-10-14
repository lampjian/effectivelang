//归并排序，mergesort
/*
建立在归并操作上的一种有效的排序算法,该算法是采用分治法（Divide and Conquer）的一个非常典型的应用。
将已有序的子序列合并，得到完全有序的序列；即先使每个子序列有序，再使子序列段间有序。
若将两个有序表合并成一个有序表，称为二路归并。
归并过程为：比较a[i]和b[j]的大小，若a[i]≤b[j]，则将第一个有序表中的元素a[i]复制到r[k]中，并令i和k分别加上1；
否则将第二个有序表中的元素b[j]复制到r[k]中，并令j和k分别加上1，如此循环下去，直到其中一个有序表取完，然后再将另一个有序表中剩余的元素复制到r中从下标k到下标t的单元。
归并排序的算法我们通常用递归实现，先把待排序区间[s,t]以中点二分，接着把左边子区间排序，再把右边子区间排序，最后把左区间和右区间用一次归并操作合并成有序的区间[s,t]。

*/

// #include "stdafx.h"
#include <iostream>
#include <vector>
#include <cstdlib>

void merge(int a[], int *tmp, int p, int q, int r)
{
	int i,leftend,num,tmpos;
	leftend = q-1;
	tmpos = p;
	num = r-p+1;
	while(p<=leftend && q<=r)
		if(a[p]<=a[q])
			tmp[tmpos++]=a[p++];
		else  
			tmp[tmpos++]=a[q++];
	while(p<=leftend)
		tmp[tmpos++]=a[p++];
	while(q<=r)
		tmp[tmpos++]=a[q++];
	for(i=0;i<num;i++,r--)
		a[r]=tmp[r];
}

void msort(int a[], int *temp, int start,int end)
{
	int q=0;
	if(start<end){
		q = (end+start)/2;
		msort(a, temp,start, q);
		msort(a, temp,q+1,end);
		merge(a,temp,start,q+1,end);
	}
}

void merge_sort(int A[],int n)
{
	int *tmp = (int *)malloc(n*sizeof(int));
	if(NULL != tmp)
	{
		for(int i=0; i<n;i++)
			tmp[i]=0;
		msort(A,tmp,0,n-1);
		free(tmp);
	}
}


int main(int argc, char* argv[])
{
	int y[] = {40,33,20,19,3,2,100,13,6,8};

	std::cout << "This is merge sort now:" << std::endl;
	merge_sort(y,10);
	for(int i=0; i<10; i++)
	{
		std::cout<<"y["<<i<<"] is:"<<y[i]<<std::endl;
	}

	using std::vector;

	vector<int *> vecTemp;
	for (int i=0; i< 10; i++)
	{
		int* nTemp = new int;
		*nTemp = i;
		vecTemp.push_back(nTemp);
	}
	vector<int *>::iterator iter;
	for(iter = vecTemp.begin(); iter != vecTemp.end(); iter++)
	{
		std::cout<<"vectTemp[] is"<<**iter<<std::endl;

	}
	// memory management
	for(int j=0; j<vecTemp.size();j++)
	{
		delete vecTemp[j];
		vecTemp[j] = NULL;
	}
	/*for(int j=0; j<vecTemp.size();j++)
	{
		std::cout << *vecTemp[j] << std::endl;
	}*/

	std::cout << "Print ENV constants." << std::endl;
	void webenv(void);
	webenv();
	return 0;
}


#include <string>

using namespace std;

void webenv(void)
{
	const string ENV[24] = {
        "COMSPEC", "DOCUMENT_ROOT", "GATEWAY_INTERFACE",
        "HTTP_ACCEPT", "HTTP_ACCEPT_ENCODING",
        "HTTP_ACCEPT_LANGUAGE", "HTTP_CONNECTION",
        "HTTP_HOST", "HTTP_USER_AGENT", "PATH",
        "QUERY_STRING", "REMOTE_ADDR", "REMOTE_PORT",
        "REQUEST_METHOD", "REQUEST_URI", "SCRIPT_FILENAME",
        "SCRIPT_NAME", "SERVER_ADDR", "SERVER_ADMIN",
        "SERVER_NAME","SERVER_PORT","SERVER_PROTOCOL",
        "SERVER_SIGNATURE","SERVER_SOFTWARE" };

		for (int i=0; i< 24; i++)
		{
			cout <<"ENV["<<i<<"] is:"<<ENV[i]<<endl;
		}
}

/*
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char** argv) {
	system("cd");
	ifstream dt("transa.txt",ios::in); // 只读打开
	ofstream ot("test.txt", ios::app);// 附加写打开

	if(dt.is_open()) { cout <<"File opened."<<endl;}
	else
	{
		cout << "File not opened."<<endl;
		return -1;
	}

	string st;
	vector<string> vi[100];
	while( NULL != getline(dt, st,'\n') )
    {
		if(st.length() != 0)
		{     
			cout << "Read from file: " <<hex<< st<< endl;
			for(int i=0; i< st.length(); i++)
			{
				int k = i;       
				if(st[i] == ' ' || st[i] == '\t') {
					st.c_str()				i++;
					continue;
				}
				else {
					vi[0].push_back(st.substr(k,i));
				}
			}
		} else
		{
			cout << "Bye"<<endl;
		}
		break;
    }

	for(int j=0; j<vi[0].size(); j++)
		cout << vi[0].at(j)<<"\n";
	dt.close();

	ot.close();
	cout << "Programs done."<<endl;
    return 0;
}

*/

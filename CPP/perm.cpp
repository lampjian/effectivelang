#include<iostream>
#include<stdio.h>

using namespace std;

template<class Type>
void Perm(Type list[],int k,int m)
{//产生list[k:m]的所有全排列
	if(k==m)
	{//只剩一个元素
		for(int i=0;i<=m;i++) cout<<list[i];
		cout<<endl;
	}
	else//还有多个元素待排列，递归产生排列
		for(int i=k;i<=m;i++)//循环交换第一个元素与其后的所有元素实现全//排列
		{
			Swap(list[k],list[i]);
			Perm(list,k+1,m);
			Swap(list[k],list[i]);
		}
}

// 我有一个非递归算法

int *n;

void arge(int *x,int size)
{
	int *t;
	int totoal=0;
	int pos=size-2;
	int just=0;
	t= new int;
	for(int i=0;i<size;i++)
		*t=1;
	while(1)
	{
		for(int i=0;i<size;i++)
			printf("%d",*(x+i));
		printf("\n");
		totoal++;
		pos=size-2;
		while(x[pos]>x[pos+1])//
		{
			pos--;
			t[x[pos+1]-1]=0;
		}
		if(pos<0)
			break;
		t[x[pos+1]-1]=0;//复位上一个
		t[x[pos]-1]=0;
		for(int i=x[pos]+1;i<=size;i++)
		{
			if(t[i-1]==0)
			{
				x[pos]=i;
				t[x[pos]]=1;
				break;
			}
		}
		t[x[pos]-1]=1;
		for(int i=pos+1;i<size;i++)
		{
			for(int j=1;j<=size;j++)
			{
				if(t[j-1]==0)
				{
					x[pos]=j;
					t[j-1]=1;
					break;
				}
			}
		}
	}
	printf("totoal=%d\n",totoal);
	delete t;
}

int main()
{
	int m;
	scanf("%d",&m);
	n=new int[m];
	for(int i=0;i<m;i++)
		n[i]=i+1;
	arge(n,m);
	delete[] n;
	return 0;
}

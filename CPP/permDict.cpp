#include <stdio.h>

int *array;
int num;
inline void xchg(int &a,int &b)
{
	int c=a;
	a=b;
	b=c;
}
//从pos到num的数据进行翻转
void invert(int pos)
{
	int count=num-pos+1;
	for(int i=0;i<count/2;i++)
		xchg(array[pos+i],array[num-i]);
}
//检查输入中是否有重复数值
bool is_valid(int data,int serial)
{
	for(int i=1;i<serial;i++)
		if(array[i]==data)
		{
			printf("全排列中不能有数据重复！\n");
			return 0;
		}
	return 1;
}
//输出全排列
void print_permutation(int m)
{
	printf("之后第%d个全排列:",m);
	for(int i=1;i<=num;i++)
		printf("%d",array[i]);
	printf("\n");
}
//字典序全排列的主体
void dictionary()
{
	printf("输入起始的全排列:\n");
	for(int i=1;i<=num;i++)
	{
		int data;
		scanf("%d",&data);
		if(is_valid(data,i))
			array[i]=data;
		else
			return;
	}
	if(num==1)
	{
		printf("只有一个数，不需进行排列！\n");
		return;
	}
	int count;
	printf("预测之后第几个序列：\n");
	scanf("%d",&count);
	//一次循环找下一个全排列
	for(int m=1;m<=count;m++)
	{
		int pos1=0;
		int pos2;
		//从num-1开始，找到第一个比右边值小的位置
		for(int j=num-1;j>0;j--)
			if(array[j]<array[j+1])
			{
				pos1=j;
				break;
			}
		if(pos1<1||pos1>num)
		{
			printf("目前全排列已为%d位数的最后一个全排列！\n\n",num);
			return;
		}
		//从num开始找array[pos1]小的第一个数的位置
		for(int n=num;n>pos1;n--)
			if(array[n]>array[pos1])
			{
				pos2=n;
				break;
			}
		xchg(array[pos1],array[pos2]);
		//从pos1+1到num的数进行翻转
		invert(pos1+1);
		print_permutation(m);
	}
}
int main()
{
	printf("输入要进行全排列的位数\n");
	scanf("%d",&num);
	array=new int[num+1];
	while(1)
		dictionary();
}


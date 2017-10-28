# include <stdio.h> //其中有标准错误stderr的说明
# include <stdlib.h> //其中有exit的说明

void Error(char*message)
{
  fprintf(stderr,"Error: %s \n ", message) ; //输出错误信息
  exit(1) ; //终止程序，返回1给操作系统
}

void selectSort(int *r, int n)
{
	//首元素作为哨兵，不存储数据 
	int *p = r,k;
	for(int i=1; i<n; i++)
	{
		k = i;
		int j;
		for(j=i+1;j<=n;j++)
		{
			if(p[j]<p[k])
			{
				k = j;
			}
		}
		if(k!=j)
		{
			p[0] = p[k];
		    p[k] = p[i];
		    p[i] = p[0];
		}
	}
	p[0] = -1;
}

void main(void)
{
	int x[] = {-1,3,6,9,88,100,2,0};
	int len = sizeof(x)/sizeof(x[0]);
	selectSort(x,len-1);
	for(int i=0;i<len;i++)
	    printf("value of x[%i]:%d.\n",i,x[i]);
	char errm[] = "No errors.";
	Error(errm);
}


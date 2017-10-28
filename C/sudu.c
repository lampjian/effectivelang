#include<stdio.h>

int check_if_ok(int *p)
{
	int i,j,temp[9],temp1[9];
	if(p[0]+p[1]+p[2]!=15)
		return -1;
	if(p[3]+p[4]+p[5]!=15)
		return -1;
	if(p[6]+p[7]+p[8]!=15)
		return -1;

	if(p[0]+p[3]+p[6]!=15)
		return -1;
	if(p[1]+p[4]+p[7]!=15)
		return -1;
	if(p[2]+p[5]+p[8]!=15)
		return -1;

	if(p[0]+p[4]+p[8]!=15)
		return -1;
	if(p[2]+p[4]+p[6]!=15)
		return -1;
	for(i=0;i<9;i++)
	{
		temp[i]=p[i];
		for(j=0;j<9;j++)
		{
			if(i==j)
				continue;
			temp1[j]=p[j];
			if(temp[i]==temp1[j])
				return -1;   /* 如果找的到相同的数字表示不符合规定 */
		}
	}
	printf("%d  %d  %d \n",p[0],p[1],p[2]);
	printf("%d  %d  %d \n",p[3],p[4],p[5]);
	printf("%d  %d  %d \n",p[6],p[7],p[8]); 
	printf("\n\n");
	return 0;
}

void main()
{
	int a[9]={1,2,3,4,5,6,7,8,9};
	int b[9]={0};
	int i,j,k,m;
	for(j=1;j<10;j++)
	{
		b[0]=j;
		for(i=1;i<10;i++)
		{
			if(i==j) 
				continue;
			b[1]=i;
			for(k=1;k<10;k++)
			{
				if((k==i)||(k==j))
					continue;
				b[2]=k;
				for(m=1;m<10;m++)
				{
					if((m==i)||(m==j)||(m==k))
						continue;
					b[3]=m;
					b[6]=15-b[0]-b[3];
					b[4]=15-b[2]-b[6];
					b[7]=15-b[1]-b[4];
					b[5]=15-b[3]-b[4];
					b[8]=15-b[2]-b[5];
					check_if_ok(b);
				}
			}
		}
	}
}

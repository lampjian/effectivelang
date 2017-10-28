#include <stdio.h>
#include <stdlib.h>

#define false 0
#define true 1

int n = 0;
short imp = false;

// pointer and temp variable
void swap(int *a, int *b)
{
    int m;
    m = *a;
    *a = *b;
    *b = m;
}
void perm(int list[], int k, int m)
{
    int i;
    if(k == m)
    {
        for(i = 0; i < m; i++)
            printf("%d ", list[i]);
		int l,num=0;
		for(i=0,l=1;i<m;i++,l*=10){
			num += list[i]*l;
		}
		printf("The number is:%d.   ",num);
		if (num%list[m] == 0 && num != list[m])
		{
			printf("Possible\n");
			imp = true;
			// exit(0);
		}
        printf("\n");
        n++;
    }
    else
    {
        for(i = k; i < m; i++)
        {
            swap(&list[k], &list[i]);
            perm(list, k + 1, m);
            swap(&list[k], &list[i]);
        }
    }
}
int main()
{
    int list[] = {0,1, 2, 3,4,20};
    perm(list, 0, 5);
	if(false == imp)
	{
		printf("Impossible\n");
	}
    printf("total:%d\n", n);
    return 0;
}

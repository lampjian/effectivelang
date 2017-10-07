#include <stdio.h>
#define MAX 100
void process(char *c,int n){
	int i = 0;
	while(i < n){
		printf("%c",c[i]);
		i++;
	}
	printf("\n");
}
void perm(char *list,int n){
	int k; 
	char tmp;
	int i = n;
	int count[MAX];
	count[i-1] = 1;
	while(i > 2){
		i--;
		count[i-1] = 1;
	}
	process(list,n);
	do{
		if(count[i-1] < i){
			if(i % 2 != 0)
				k = 1;
			else
				k = count[i-1];
			tmp = list[k-1];
			list[k-1] = list[i-1];
			list[i-1] = tmp;
			count[i-1] += 1;
			i = 2;
			process(list,n);
		}else{
			count[i-1] = 1;
			i += 1;
		}
	}while(i <= n);
}
int main(){
	char c[] = {'a','b','c','d'};
	perm(c,4);
	// int a[] = {1,8,4,2,0,9};
	// perm(a,6);
}


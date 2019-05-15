
#include <stdio.h>
#define N 8

void show(int a[]);
void bubblesort(int a[]);
int main(void)
{
	int a[N] = {50,36,66,76,95,12,25,36};

	show(a);
	bubblesort(a);

	return 0;
}

void bubblesort(int a[])
{
	int i,j,t,flag;
	for(i = 0; i < N-1; i++){
		flag = 1;
		for(j = 0; j < N-1-i; j++)
			if(a[j] > a[j+1]){
				t = a[j];
				a[j] = a[j+1];
				a[j+1] = t;
				flag = 0;
			}
		if(flag == 1)   //记录已经有序，则结束排序
			break;
		printf("第%d趟:",i+1);
		show(a);
	}
}

void show(int a[])
{
	int i;
	for(i = 0; i < N; i++)
		printf("%d\t",a[i]);
	printf("\n");
}


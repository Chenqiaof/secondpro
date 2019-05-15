#include <stdio.h>
#define N 8

void show(int a[]);
int quick_pass(int a[],int i,int j);
void quicksort(int a[],int low,int high);
int main(void)
{
	int a[N] = {50,36,66,76,36,12,25,95};

	show(a);
	quicksort(a,0,N-1);

	return 0;
}
//一趟快速排序
int quick_pass(int a[],int i,int j)
{
	int t = a[i];
	while(i < j){
		while(i < j && t <= a[j])
			j--;
		if(i < j)
			a[i] = a[j];
		while(i < j && t >= a[i])
			i++;
		if(i < j)
			a[j] = a[i];
	}
	a[i] = t;
	return i;
}

void quicksort(int a[],int low,int high)
{
	int mid;

	if(low < high){
		mid = quick_pass(a,low,high);  //一趟快速排序
		show(a);
		quicksort(a,low,mid-1);
		quicksort(a,mid+1,high);
	}
}

void show(int a[])
{
	int i;
	for(i = 0; i < N; i++)
		printf("%d\t",a[i]);
	printf("\n");
}


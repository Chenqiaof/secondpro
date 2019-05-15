#include <stdio.h>
#define N 8

void show(int a[]);
void binsort(int a[]);
int main(void)
{
	int a[N] = {50,36,66,76,95,12,25,36};

	show(a);
	binsort(a);

	return 0;
}

void binsort(int a[])
{
	int i,j,t;
	int low,high,mid;
	for(i = 1;i < N; i++){
		t = a[i];   //保存待排序中的第一个记录
		//寻找插入t的位置
		for(low = 0,high = i-1;low <= high;){
			mid = (low + high) / 2;
			if(t <= a[mid])
				high = mid - 1;
			else
				low = mid + 1;
		}
		//移动数据
		for(j = i; j > low; j--)
			a[j] = a[j-1];
		a[low] = t; //将t插入j+1的位置
		printf("第%d趟:",i);
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


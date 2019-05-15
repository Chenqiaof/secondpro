#include <stdio.h>
#define N 10

void show(int a[]);
void shellsort(int a[]);
int main(void)
{
	int a[N] = {50,36,66,76,95,12,25,36,24,8};

	show(a);
	shellsort(a);

	return 0;
}

void shellsort(int a[])
{
	int i,j,t,d,k = 0;
	for(d = N/2; d > 0; d /= 2){
		for(i = d;i < N; i++){
			t = a[i];   //保存待排序中的第一个记录
			//寻找插入t的位置，同时将数据后移
			for(j = i-d;j >= 0; j -= d)
				if(t < a[j])
					a[j+d] = a[j];
				else
					break;
			a[j+d] = t; //将t插入j+1的位置
		}
		printf("第%d趟:",++k);
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


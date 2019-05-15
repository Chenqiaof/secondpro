#include <stdio.h>
#include <unistd.h>

#define N 8

void seqsort(int a[]);
void show(int a[]);
int main(void)
{
      int a[] = {50,36,66,76,95,12,25,36};
      show(a);
      seqsort(a);  //排序
      return 0;
}

void seqsort(int a[])
{
      int i,j,t;

      for(i = 1;i < N; i++){
	    t = a[i];  //将i位置的记录保存当t中

	    //在有序记录中寻找t的位置
	    for(j = i-1; j >= 0;j--)
		  if(t < a[j])
			a[j+1] = a[j];
		  else
			break;
	    a[j+1] = t;	 //将t插入到j+1的位置
	    printf("第%d趟:",i);
	    show(a);
	    sleep(1);
      }
}

void show(int a[])
{
      int i;

      for(i = 0 ; i < N; i++)
	    printf("%d\t",a[i]);
      printf("\n");
}

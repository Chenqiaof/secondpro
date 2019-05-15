#include "search.h"

void show(int a[]);
int main(void)
{
      int a[N] = {3,12,18,20,32,55,60,68,80,86,90,100};
      int ret,key;
      char ch;

     show(a);
      while(1){
	    printf("请输入key:");
	    scanf("%d",&key);
	    ret = binsearch(a,key);
	    if(ret == -1){  //查找失败
		  printf("查找失败\n");
	    }else{  //查找成功
		  printf("查找成功,key为%d的记录在%d位置!\n",key,ret);
	    }
	    printf("是否继续?(Y/y)");
	    while(getchar() != '\n');  //清空缓冲区
	    scanf("%c",&ch);
	    if(!(ch == 'Y' || ch == 'y'))
		  break;
      }
      return 0;
}

void show(int a[])
{
    int i;

    for( i = 0 ; i < N-1; i++)
	printf("%d\t",a[i]);
    printf("\n");
}


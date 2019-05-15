#include "hash.h"
#define SEQSEACH

#ifdef SEQSEACH
int main(void)
{
    int a[N] = {23,34,14,38,46,16,68,15,07,31,26};
    int ret,key,m;
    char ch;
    h_tp h;

    m = (int)ceil(N/0.75);   //计算hash表的长度
    h = init_ht(m);	//初始化hash表
    create_ht(a,h);   //创建hash表
#if 1
    while(1){
	printf("请输入要查找的记录的key:");
	scanf("%d",&key);
	ret = hash_search(h,key);
	if(ret == -1)
	    printf("您要查找的记录不存在!\n");
	else{
	    printf("查找成功！\n");
	    printf("key为%d的记录在%d的位置\n",key,ret);
	}
	while(getchar() != '\n');   //清空输入缓冲区
	printf("是否继续(Y/y)?");
	scanf("%c",&ch);
	if(ch != 'Y' && ch != 'y')
	    break;
    }
#endif
    return 0;
}

#endif

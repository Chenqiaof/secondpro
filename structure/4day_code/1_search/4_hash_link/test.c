#include "hash.h"
#define SEQSEACH

#ifdef SEQSEACH
int main(void)
{
    datatype a[N] = {{23,1.1},{34,2.2},{14,3.3},{38,4.3},{46,2.1},{16,5.4},{68,4.5},{15,4.7},{07,4.9},{31,5.2},{26,7.8}};
    int key,m;
    char ch;
    h_tp h;
    hash_pnode  ret;

    m = (int)ceil(N/0.75);
    h = init_ht(m);	//初始化hash表
    create_ht(a,h);   //创建hash表
#if 1
    while(1){
	printf("请输入要查找的记录的key:");
	scanf("%d",&key);
	ret = hash_search(h,key);
	if(ret == NULL)
	    printf("您要查找的记录不存在!\n");
	else{
	    printf("查找成功！\n");
	    printf("key为%d的记录为：key = %d,f = %f\n",key,ret->data.key,ret->data.f);
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

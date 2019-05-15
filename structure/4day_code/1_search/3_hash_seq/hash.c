#include "hash.h"

int p;

h_tp init_ht(int m)
{
    h_tp h;
    h = (h_tp)malloc(sizeof(h_tb));
    if(NULL == h){
	printf("malloc failed!\n");
	exit(1);
    }
    h->hlen = m;
    h->hp = (datatype*)malloc(m*sizeof(datatype));
    if(NULL == h->hp){
	printf("malloc failed!\n");
	exit(1);
    }
    int i;
    for(i = 0; i < m; i++)
	h->hp[i] = -1;
    return h;
}
//计算不大与m的最大质数
int fun(int m)
{
    int i,j;
    for(i = m; i > 1; i--){
	for(j = 2; j < i; j++)
	    if(i%j == 0)
		break;
	if(j == i)
	    return i;
    }
    return -1;
}
//创建hash表
void create_ht(int a[],h_tp h)
{
    int i,hash_val;

    p = fun(h->hlen);
    for(i = 0; i < N; i++){
	//用保留余数法构建hash函数
	hash_val = a[i] % p;
	//如果hash_val位置有冲突，则用线性探查法处理冲突
	while(h->hp[hash_val] != -1)
	    hash_val = (hash_val + 1) % h->hlen;
	h->hp[hash_val] =a[i];
	show_hashtb(h,hash_val);
	sleep(1);
    }  
}

int hash_search(h_tp h,int key)
{
    int hash_val,flag = 0;
    hash_val = key % p;
    //如果有冲突则，需要少数的比较来确定key的记录位置
    while(key != h->hp[hash_val]){
	    hash_val = (hash_val + 1) % h->hlen;
	    flag++;
	    if(h->hp[hash_val] == -1 ||flag > h->hlen)
		return -1;
    }
    return hash_val;
}

void show_hashtb(h_tp h,int hash_val)
{
    int i;

    for(i = 0; i < h->hlen; i++){
	  if(i == hash_val)
	      printf("h->hp[%02d]: <-----%d\n",i,h->hp[i]);
	  else
	      printf("h->hp[%02d]:%d\n",i,h->hp[i]);
    }
    printf("*******************************\n");
}

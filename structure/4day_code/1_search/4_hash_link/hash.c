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
    h->hp = (hash_pnode*)malloc(m*sizeof(hash_pnode));
    if(NULL == h->hp){
	printf("malloc failed!\n");
	exit(1);
    }
    int i;
    for(i = 0; i < m; i++)
	h->hp[i] = NULL;
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

void create_ht(datatype a[],h_tp h)
{
    int i,hash_val;
    hash_pnode new;

    p = fun(h->hlen);
    for(i = 0; i < N; i++){
	//用保留余数法构建hash函数
	hash_val = a[i].key % p;
	//如果hash_val位置有冲突，则链地址法处理冲突：将有冲突的结点插入到同一个链表中
	new = (hash_pnode)malloc(sizeof(hash_node));
	if(NULL == new){
	    printf("malloc failed!\n");
	    exit(1);
	}
	new->data = a[i];
	//将new结点插入到hash_val位置的指针指向的链表中
	new->next = h->hp[hash_val];
	h->hp[hash_val] = new;

	show_hashtb(h);
	sleep(1);
    }  
}

hash_pnode  hash_search(h_tp h,int key)
{
    int hash_val;
    hash_pnode t;
    hash_val = key % p;
    //如果有冲突则，需要少数的比较来确定key的记录位置
    for(t = h->hp[hash_val];t != NULL;t = t->next){
	if(key == t->data.key)
	    break;
    }
    return t;
}

void show_hashtb(h_tp h)
{
    int i;
    hash_pnode t;

    for(i = 0; i < h->hlen; i++){
	if(h->hp[i] == NULL)
	    printf("h->hp[%02d]:--->%c",i,'^');
	else{
	    printf("h->hp[%02d]:",i);
	    for(t = h->hp[i];t != NULL; t = t->next)
		printf("--->%d",t->data.key);
	}
	printf("\n");
    }
    printf("*******************************\n");
}

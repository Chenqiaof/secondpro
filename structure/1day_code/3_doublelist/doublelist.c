#include "doublelist.h"

//初始化
double_plist doublelist_init(void)
{
    double_plist h;

    //申请头节点空间
    h = (double_plist)malloc(sizeof(double_list));
    if(NULL == h)
    {
	perror("malloc");
	exit(1);
    }

    h->next = h;
    h->prev= h;

    return h;
}
//插入--后插，如果h为头节点的指针，则是向表头插入
void doublelist_insert(double_plist p,double_plist new)
{
    new->next = p->next;
    p->next->prev = new;
    new->prev = p;
    p->next = new;
}
//插入--前插，如果h为头节点的指针，则是向表尾插入
void doublelist_insert_tail(double_plist p,double_plist new)
{
    new->prev = p->prev;
    p->prev->next = new;
    new->next = p;
    p->prev = new;
}
//删除
void doublelist_del(double_plist p)  //p表示要删除的节点的指针
{
    p->prev->next = p->next;
    p->next->prev = p->prev;
}
//判断空
bool doublelist_isempty(double_plist h)
{
    if(h->next == h)
	return true;
    else
	return false;
}
//遍历
void doublelist_show(double_plist h)
{
    double_plist p;

    for(p = h->next; p != h; p = p->next)
	printf("%d\t",p->data);
    printf("\n");
}

void doublelist_create(double_plist h)
{
    int n,i;
    double_plist new,p = h;

    printf("请输入链表的数据个数:");
    scanf("%d",&n);
    
    for(i = 0; i < n; i++){
	new = (double_plist)malloc(sizeof(double_list));	
	if(NULL==new){
	    perror("malloc");
	    exit(1);
	}
	printf("请输入数据:");
	scanf("%d",&new->data);

	doublelist_insert_tail(h,new);
	doublelist_show(h);
    }
}

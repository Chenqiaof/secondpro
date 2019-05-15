#include "linklist.h"

//初始化
link_plist linklist_init(void)
{
    link_plist h;

    //申请头节点空间
    h = (link_plist)malloc(sizeof(link_list));
    if(NULL == h)
    {
	perror("malloc");
	exit(1);
    }

    h->next = NULL;

    return h;
}
//插入
void linklist_insert(link_plist p,link_plist new)
{
    new->next = p->next;
    p->next = new;
}
//删除
void linklist_del(link_plist p)  //p表示要删除的节点前一个节点地址
{
    link_plist t;

    t = p->next;
    p->next = t->next;
    free(t);
}
//判断空
bool linklist_isempty(link_plist h)
{
    if(h->next == NULL)
	return true;
    else
	return false;
}
//遍历
void linklist_show(link_plist h)
{
    link_plist p;

    for(p = h->next; p != NULL; p = p->next)
	printf("%d\t",p->data);
    printf("\n");
}

void linklist_create(link_plist h)
{
    int n,i;
    link_plist new,p = h;

    printf("请输入链表的数据个数:");
    scanf("%d",&n);
    
    for(i = 0; i < n; i++){
	new = (link_plist)malloc(sizeof(link_list));	
	if(NULL==new){
	    perror("malloc");
	    exit(1);
	}
	printf("请输入数据:");
	scanf("%d",&new->data);

	linklist_insert(p,new);

	p = p->next;
	linklist_show(h);
    }
}

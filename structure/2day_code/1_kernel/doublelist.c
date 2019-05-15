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

    INIT_LIST_HEAD(&h->list);

    return h;
}

//判断空
bool doublelist_isempty(double_plist h)
{
    if(h->list.next == &h->list)
	return true;
    else
	return false;
}
//遍历
void doublelist_show(double_plist h)
{
    double_plist p;

    list_for_each_entry(p,&h->list,list){
	printf("%d\t",p->data);
    }
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

	//doublelist_insert_tail(h,new);
	list_add_tail(&new->list,&h->list);
	doublelist_show(h);
    }
}

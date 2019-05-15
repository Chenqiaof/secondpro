/*
 用单向链表实现数据逆转，首先建立一个包含若干整数的单向链表，然后参考讲义的例子实现数据的逆转。（比如说把1，2，3，4，5逆转成5，4，3，2，1）
 */

#include "linklist.h"

void linklist_sort(link_plist h);
int main(void)
{
    link_plist h;

    h  = linklist_init();
    //建立一个单向链表
    linklist_create(h);

    //链表数据的逆转
    linklist_sort(h);
    return 0;
}


void linklist_sort(link_plist h)
{
    link_plist p,t;

    p  = h->next;
    h->next = NULL;

    while(p  != NULL){
	t = p;
	p = p->next;
	linklist_insert(h,t);

	linklist_show(h);
    }
}

/*
研读内核代码，用LINUX内核函数提供的双向循环链表标准实现重做第4题（选做）
 */

#include "doublelist.h"

void doublelist_sort(double_plist h);
int main(void)
{
    double_plist h;

    h  = doublelist_init();
    //建立一个双向循环链表
    doublelist_create(h);

    //链表数据排序
    doublelist_sort(h);
    return 0;
}


void doublelist_sort(double_plist h)
{
    double_plist p,t;

    p = list_entry(h->list.prev,double_list,list);

    while(p != h){
	if(p->data % 2 != 0)  //奇数
	    p = list_entry(p->list.prev,double_list,list);
	else{	    //偶数
	    t = p;
	    p = list_entry(p->list.prev,double_list,list);

	    list_move_tail(&t->list,&h->list);
	    doublelist_show(h);
	}
    }
}

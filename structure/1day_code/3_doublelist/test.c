/*
   用双向循环链表实顺序递增存储若干自然数，比如输入一个整数10，则建立一个双向循环链表，里面的每个节点分别存放1，2，3，4，5，6，7，8，9，10，然后通过某些操作，将其重新排列成1，3，5，7，9，10，8，6，4，2，即奇数升序偶数降序，并在屏幕上打印出来。
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

    p = h->prev;

    while(p != h){
	if(p->data % 2 != 0)  //奇数
	    p = p->prev;
	else{	    //偶数
	    t = p;
	    p = p->prev;

	    doublelist_del(t); //将t指向的节点剪切出来
	    doublelist_insert_tail(h,t); //将t指向的节点插入到表尾

	    doublelist_show(h);
	}
    }
}

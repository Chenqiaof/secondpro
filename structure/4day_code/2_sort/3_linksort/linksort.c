#include "linklist.h"
#define N 8

void linksort(link_plist h);
int main(void)
{
	link_plist h;

	init_linklist(&h);	
	create_linklist(h);
	linksort(h);

	return 0;
}

void linksort(link_plist h)
{
	link_plist p,q,t1,t2;

	p = h->next;
	h->next = NULL;

	while(p != NULL){
		q = p;
		p = p->next;
		//在h指向的链表中寻找q指向的结点的位置
		t1 = h;
		t2 = h->next;
		while(t2 != NULL && q->data > t2->data){
			t1 = t2;
			t2 = t2->next;
		}
		//将q指向的结点插入到t1和t1指向的结点之间
		q->next = t2;
		t1->next = q;
		show_linklist(h);
	}
}


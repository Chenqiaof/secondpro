#include "linklist.h"


void init_linklist(link_plist *H)
{
	*H = (link_plist)malloc(sizeof(link_list));
	if(NULL == *H){
		perror("malloc");	//打印出malloc失败的原因 
		exit(1);  //结束程序
	}
	(*H)->next = NULL;
}

void insert_linklist(link_plist h,link_plist new)
{
	new->next = h->next;
	h->next = new;
}

void create_linklist(link_plist h)
{
	int i,n;
	link_plist new,p = h;
	printf("请输入链表的长度:");
	scanf("%d",&n);
	for(i = 0; i < n; i++){
		new = (link_plist)malloc(sizeof(link_list));
		if(NULL == new){
			perror("malloc");	//打印出malloc失败的原因 
			exit(1);  //结束程序
		}
		scanf("%d",&new->data);
		insert_linklist(p,new);
		p = p->next;
		show_linklist(h);
	}

}
void del_linklist(link_plist p)
{
	link_plist t;

	t = p->next;
	p->next = t->next;
	free(t);
}
void show_linklist(link_plist h)
{
	link_plist p;
	for( p = h->next; p != NULL; p = p->next)
		printf("%d\t",p->data);
	printf("\n");
}

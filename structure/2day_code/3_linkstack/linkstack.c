#include "linkstack.h"

//初始化
link_pstack linkstack_init(void)
{
    return NULL;
}

//入栈
void linkstack_push(link_pstack *Top,datatype data)
{
    link_pstack new;

    new = (link_pstack)malloc(sizeof(link_stack));
    if(NULL == new){
	printf("没有申请到节点空间!\n");
	return ;
    }
    new->data = data;

    new->next = *Top;
    *Top = new;
}

//出栈
void linkstack_pop(link_pstack *Top,datatype *D)
{
    link_pstack t;

    if(linkstack_isempty(*Top)){
	printf("表为空!\n");
	return ;
    }
    
    t = *Top;
    *Top = (*Top)->next;
    *D = t->data;
    free(t);
}
//判断表为空
bool linkstack_isempty(link_pstack top)
{
    if(top == NULL)
	return true;
    else
	return false;
}

//遍历
void linkstack_show(link_pstack top)
{
    link_pstack p;

    for(p = top; p != NULL; p = p->next)
	printf("%d\t",p->data);
    printf("\n");
}

#include "linkqueue.h"

//初始化
link_pqueue linkqueue_init(void)
{
    link_pqueue q;

    //申请循环队列的空间
    q = (link_pqueue)malloc(sizeof(link_queue));  //front和rear的空间
    if(NULL == q){
	perror("malloc");
	exit(1);
    }

    q->front = (queue_pnode)malloc(sizeof(queue_node)); //头节点空间
    q->front->next = NULL;

    q->rear = q->front;

    return q;
}

//入队
void linkqueue_in(link_pqueue q,datatype data)
{
    queue_pnode new;

    new = (queue_pnode)malloc(sizeof(queue_node));
    if(NULL == new){
	perror("malloc");
	return ;	
    }
    new->data = data;

    new->next = q->rear->next;
    q->rear->next = new;
    q->rear = q->rear->next;
}

//出队
bool linkqueue_out(link_pqueue q,datatype *D)
{
    queue_pnode t;
    //判断队列是否为空
    if(linkqueue_isempty(q)){
	printf("表为空!\n");
	return false;
    }

    t = q->front;
    q->front = q->front->next;
    *D = q->front->data;
    free(t);
    return true;
}
//判断队列为空
bool linkqueue_isempty(link_pqueue q)
{
    if(q->front == q->rear)
	return true;
    else
	return false;
}

#if 0
//遍历
void linkqueue_show(link_pqueue q)
{
    queue_pnode p;
    for(p = q->front->next; p != NULL ; p = p->next)
	printf("%d\t",p->data);
    printf("\n");
}
#endif

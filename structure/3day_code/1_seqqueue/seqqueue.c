#include "seqqueue.h"

//初始化
seq_pqueue seqqueue_init(void)
{
    seq_pqueue q;

    //申请循环队列的空间
    q = (seq_pqueue)malloc(sizeof(seq_queue));
    if(NULL == q){
	perror("malloc");
	exit(1);
    }

    q->front = q->rear = SIZE -1;

    return q;
}

//入队
void seqqueue_in(seq_pqueue q,datatype data)
{

    //判断队列满
    if(seqqueue_isfull(q)){
	printf("队列已满!\n");
	return ;	//队列满则返回
    }

    //不满，则入队
    q->rear = (q->rear+1)%SIZE;
    q->data[q->rear] = data;
}

//出队
void seqqueue_out(seq_pqueue q,datatype *D)
{

    if(seqqueue_isempty(q)){
	printf("表为空!\n");
	return ;
    }
    
    q->front = (q->front+1)%SIZE;
    *D = q->data[q->front];
}
//判断队列为空
bool seqqueue_isempty(seq_pqueue q)
{
    if(q->front == q->rear)
	return true;
    else
	return false;
}

//判断队列满
bool seqqueue_isfull(seq_pqueue q)
{
    if(q->front == (q->rear+1)%SIZE)
	return true;
    else
	return false;
}

//遍历
void seqqueue_show(seq_pqueue q)
{
    int i;

    for(i = (q->front+1)%SIZE; i != (q->rear+1)%SIZE; i = (i+1)%SIZE)
	printf("%d\t",q->data[i]);
    printf("\n");
}

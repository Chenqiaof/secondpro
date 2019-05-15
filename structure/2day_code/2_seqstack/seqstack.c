#include "seqstack.h"

//初始化
seq_pstack seqstack_init(void)
{
    seq_pstack s;

    //申请顺序表的空间
    s = (seq_pstack)malloc(sizeof(seq_stack));
    if(NULL == s){
	perror("malloc");
	exit(1);
    }

    s->top = -1;

    return s;
}

//入栈
void seqstack_push(seq_pstack s,datatype data)
{

    if(seqstack_isfull(s)){
	printf("栈已满!\n");
	return ;
    }

    s->top++;
    s->data[s->top] = data;
}

//出栈
void seqstack_pop(seq_pstack s,datatype *D)
{

    if(seqstack_isempty(s)){
	printf("表为空!\n");
	return ;
    }

    *D = s->data[s->top];
    s->top--;
}
//判断表为空
bool seqstack_isempty(seq_pstack s)
{
    if(s->top == -1)
	return true;
    else
	return false;
}

//判断表满
bool seqstack_isfull(seq_pstack s)
{
    if(s->top == SIZE-1)
	return true;
    else
	return false;
}

//遍历
void seqstack_show(seq_pstack s)
{
    int i;

    for(i = s->top; i >= 0; i--)
	printf("%d\t",s->data[i]);
    printf("\n");
}

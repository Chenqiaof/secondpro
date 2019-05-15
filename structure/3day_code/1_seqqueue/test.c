/*
 分别用循环队列实现如下功能：用户从键盘输入整数，程序将其入队，用户输入字母，程序将队头元素出队，并在每一次出队和入队之后打印队列元素。
 */
#include "seqqueue.h"

int main(void)
{
    seq_pqueue q;
    datatype data,t;
    int ret;

    q = seqqueue_init();

    while(1){
	printf("请输入一个整数:");
	ret  = scanf("%d",&data);
	if(ret == 1){   //输入为整数,入队
	    seqqueue_in(q,data);
	    seqqueue_show(q);
	}else{  //输入为字符，则出队
	    seqqueue_out(q,&t);	
	    printf("out is %d\n",t);
	    seqqueue_show(q);
	    while(getchar()!= '\n');
	}
    }

    return 0;
}


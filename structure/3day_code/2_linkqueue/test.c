/*
 分别用链式队列实现如下功能：用户从键盘输入整数，程序将其入队，用户输入字母，程序将队头元素出队，并在每一次出队和入队之后打印队列元素。
 */
#include "linkqueue.h"

int main(void)
{
    link_pqueue q;
    datatype data,t;
    int ret;

    q = linkqueue_init();

    while(1){
	printf("请输入一个整数:");
	ret  = scanf("%d",&data);
	if(ret == 1){   //输入为整数,入队
	    linkqueue_in(q,data);
	    linkqueue_show(q);
	}else{  //输入为字符，则出队
	    if(linkqueue_out(q,&t))
		printf("out is %d\n",t);
	    linkqueue_show(q);
	    while(getchar()!= '\n');
	}
    }

    return 0;
}


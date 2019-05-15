#include "linkstack.h"

int main(void)
{
    link_pstack top;
    datatype data,t,m;

    top = linkstack_init();

    printf("请输入十进制数:");
    scanf("%d",&data);
    m  = data;

    if(data < 0)
	data = -data;
    while(data){
	linkstack_push(&top,data%8);
	data /= 8;
    }

    if(m < 0)
	printf("八进制数为:-0");
    else
	printf("八进制数为:0");
    while(!linkstack_isempty(top)){
	linkstack_pop(&top,&t);
	printf("%d",t);
    }
    printf("\n");
    return 0;
}


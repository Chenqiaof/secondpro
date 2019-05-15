#include "seqstack.h"

int main(void)
{
    seq_pstack s;
    datatype data,t,m;

    s = seqstack_init();

    printf("请输入十进制数:");
    scanf("%d",&data);
    m  = data;

    if(data < 0)
	data = -data;
    while(data){
	seqstack_push(s,data%8);
	data /= 8;
    }

    if(m < 0)
	printf("八进制数为:-0");
    else
	printf("八进制数为:0");
    while(!seqstack_isempty(s)){
	seqstack_pop(s,&t);
	printf("%d",t);
    }
    printf("\n");
    return 0;
}


/*
 1、用顺序表存储一些正整数，输入正整数表示插入数据（比如输入3表示插入3），输入负整数表示删除数据（比如输入-2表示删除2），输入字符表示退出程序。插入和删除的过程中保持该表递增有序。
 */

#include "seqlist.h"

void insert(seq_plist l,datatype data);
void del(seq_plist l,datatype data);

int main(void)
{
    seq_plist l;
    datatype data;
    int ret;

    l = seqlist_init();
    while(1){
	printf("请输入数据:");
	ret = scanf("%d",&data);
	if(ret != 1){    //输入为字符，退出程序
	    exit(0);
	}else if(data > 0){ //输入为正整数，插入data
	    insert(l,data);
	    seqlist_show(l);
	}else if(data < 0){ //输入为负整数，删除-data
	    del(l,-data);
	    seqlist_show(l);
	}
    }

    return 0;
}

void insert(seq_plist l,datatype data)
{
    int i;
    //1,寻找插入data的位置
    for(i = 0; i <= l->last; i++){
	if(data < l->data[i])
	    break;
    }
    //2,调用顺序表的插入算法插入data
    seqlist_insert(l,data,i);
}

void del(seq_plist l,datatype data)
{
    int i;
    //判断data在不在顺序表中
    for(i = 0 ; i <= l->last; i++)
	if(data == l->data[i])
	    break;
    if(i> l->last)		
	printf("%d不存在!\n",data);	//不存在，打印信息
    else
	seqlist_del(l,i);   //如果存在，则删除
}



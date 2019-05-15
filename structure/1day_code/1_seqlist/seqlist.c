#include "seqlist.h"

//初始化
seq_plist seqlist_init(void)
{
    seq_plist l;

    //申请顺序表的空间
    l = (seq_plist)malloc(sizeof(seq_list));
    if(NULL == l){
	perror("malloc");
	exit(1);
    }

    //last=-1
    l->last = -1;

    return l;
}

//插入数据
//l ----顺序表空间
//data--插入的数据
//i ---- 插入的位置
void seqlist_insert(seq_plist l,datatype data,int i)
{
    int j;

    if(seqlist_isfull(l)){
	printf("表已满!\n");
	return ;
    }

    //把i到last之间的数据向后移动一个位置
    for(j = l->last; j >= i; j--)
	l->data[j+1] = l->data[j];

    //将data插入到i的位置
    l->data[i] = data;

    //last+1
    l->last++;
}

//删除数据
void seqlist_del(seq_plist l,int i)
{
    int j;

    if(seqlist_isempty(l)){
	printf("表为空!\n");
	return ;
    }

    //向前覆盖i位置的数据
    for(j = i; j < l->last; j++)
	l->data[j] = l->data[j+1];

    //last-1

    l->last--;
}
//判断表为空
bool seqlist_isempty(seq_plist l)
{
    if(l->last == -1)
	return true;
    else
	return false;
}

//判断表满
bool seqlist_isfull(seq_plist l)
{
    if(l->last == SIZE-1)
	return true;
    else
	return false;
}

//遍历
void seqlist_show(seq_plist l)
{
    int i;

    for(i = 0; i <= l->last; i++)
	printf("%d\t",l->data[i]);
    printf("\n");
}

#ifndef __SEQLIST_H_
#define __SEQLIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 10
typedef int datatype;

typedef struct seqstack{
    datatype data[SIZE];
    int top;	    //top表示保存栈顶数据的下标
}seq_stack,*seq_pstack;

extern seq_pstack seqstack_init(void);
extern void seqstack_push(seq_pstack s,datatype data);
extern void seqstack_pop(seq_pstack s,datatype *D);
extern bool seqstack_isempty(seq_pstack s);
extern bool seqstack_isfull(seq_pstack s);
extern void seqstack_show(seq_pstack s);

#endif

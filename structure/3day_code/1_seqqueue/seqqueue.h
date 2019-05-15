#ifndef __SEQLIST_H_
#define __SEQLIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 10
typedef int datatype;

typedef struct seqqueue{
    datatype data[SIZE];
    int front;	    //front为队头前一个位置的下标
    int rear;	    //rear为队尾的下标
}seq_queue,*seq_pqueue;

extern seq_pqueue seqqueue_init(void);
extern void seqqueue_in(seq_pqueue q,datatype data);
extern void seqqueue_out(seq_pqueue q,datatype *D);
extern bool seqqueue_isempty(seq_pqueue q);
extern bool seqqueue_isfull(seq_pqueue q);
extern void seqqueue_show(seq_pqueue q);

#endif

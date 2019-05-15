#ifndef __LINKLIST_H_
#define __LINKLIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "btree.h"


typedef btree_pnode datatype;

typedef struct queuenode{
    datatype data;
    struct queuenode *next;
}queue_node,*queue_pnode;

typedef struct linkqueue{
    queue_pnode front;	    //front为指向队头前一个节点的指针
    queue_pnode rear;	    //rear为队尾的节点指针
}link_queue,*link_pqueue;

extern link_pqueue linkqueue_init(void);
extern void linkqueue_in(link_pqueue q,datatype data);
extern bool linkqueue_out(link_pqueue q,datatype *D);
extern bool linkqueue_isempty(link_pqueue q);
extern bool linkqueue_isfull(link_pqueue q);
//extern void linkqueue_show(link_pqueue q);

#endif

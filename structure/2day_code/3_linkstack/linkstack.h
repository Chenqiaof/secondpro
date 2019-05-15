#ifndef __LINKSTACK_H_
#define __LINKSTACK_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 10
typedef int datatype;

typedef struct linkstack{
    datatype data;
    struct linkstack *next;
}link_stack,*link_pstack;

extern link_pstack linkstack_init(void);
extern void linkstack_push(link_pstack *Top,datatype data);
extern void linkstack_pop(link_pstack *Top,datatype *D);
extern bool linkstack_isempty(link_pstack top);
extern void linkstack_show(link_pstack top);

#endif

#ifndef __LINKLIST_H__
#define __LINKLIST_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int datatype;
typedef struct linklist{
    datatype data;
    unsigned long time;
    char data[32];
    struct linklist *next;
}link_list,*link_plist;


extern link_plist linklist_init(void);
extern void linklist_insert(link_plist p,link_plist new);
extern void linklist_del(link_plist p);  //p表示要删除的节点前一个节点地址
extern bool linklist_isempty(link_plist h);
extern void linklist_show(link_plist h);

extern void linklist_create(link_plist h);
#endif

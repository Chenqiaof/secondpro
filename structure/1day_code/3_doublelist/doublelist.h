#ifndef __DOUBLELIST_H__
#define __DOUBLELIST_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int datatype;
typedef struct doublelist{
    datatype data;
    struct doublelist *next,*prev;
}double_list,*double_plist;


extern double_plist doublelist_init(void);
extern void doublelist_insert(double_plist p,double_plist new);
extern void doublelist_insert_tail(double_plist p,double_plist new);
extern void doublelist_del(double_plist p);  
extern bool doublelist_isempty(double_plist h);
extern void doublelist_show(double_plist h);

extern void doublelist_create(double_plist h);
#endif

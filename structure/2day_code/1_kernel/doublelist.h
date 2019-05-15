#ifndef __DOUBLELIST_H__
#define __DOUBLELIST_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"

typedef int datatype;
typedef struct doublelist{
    datatype data;
    struct list_head list;
}double_list,*double_plist;


extern double_plist doublelist_init(void);
extern bool doublelist_isempty(double_plist h);
extern void doublelist_show(double_plist h);

extern void doublelist_create(double_plist h);
#endif

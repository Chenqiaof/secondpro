#ifndef __SEQLIST_H_
#define __SEQLIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 10
typedef int datatype;

typedef struct seqlist{
    datatype data[SIZE];
    int last;
}seq_list,*seq_plist;

extern seq_plist seqlist_init(void);
extern void seqlist_insert(seq_plist l,datatype data,int i);
extern void seqlist_del(seq_plist l,int i);
extern bool seqlist_isempty(seq_plist l);
extern bool seqlist_isfull(seq_plist l);
extern void seqlist_show(seq_plist l);
#endif

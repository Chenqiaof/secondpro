#ifndef __HASH_H__
#define __HASH_H__

#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 11
typedef  int datatype;

typedef struct {
    datatype *hp;   //hp指向hash表空间的指针
    int hlen;	    //hlen为hash表空间的长度
}h_tb,*h_tp;

extern h_tp init_ht(int m);
extern void create_ht(int a[],h_tp h);
extern void show_hashtb(h_tp h,int hash_val);
extern int hash_search(h_tp h,int key);
#endif

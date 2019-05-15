#ifndef __HASH_H__
#define __HASH_H__

#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 11
typedef struct A{
      int key;
      float f;    
}datatype;
typedef struct hashnode{
    datatype data;
   struct hashnode *next; 
}hash_node,*hash_pnode;

typedef struct {
    hash_pnode *hp;   //hp指向hash表空间的指针
    int hlen;	    //hlen为hash表空间的长度
}h_tb,*h_tp;

extern h_tp init_ht(int m);
extern void create_ht(datatype a[],h_tp h);
extern void show_hashtb(h_tp h);
extern hash_pnode  hash_search(h_tp h,int key);
#endif

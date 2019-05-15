#include <stdio.h>
#include "list.h"

typedef struct A{
    int a;
    int b;
    float c;   //member
    double d;
}type;

int main(void)
{
    struct A st = {100,200,2.4,5.6}; 
    struct A st2 = st1;
    float *ptr;

    ptr = &st.c;

    struct A *p;

    //p = &st;
#if 0
    p = list_entry(ptr,struct A,c);
#else
    p = list_entry(ptr,type,c);
#endif

    printf("%d,%d,%f,%f\n",p->a,p->b,p->c,p->d);

    return 0;
}

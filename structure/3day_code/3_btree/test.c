#include "btree.h"

int main(void)
{
    btree_pnode t;

    t = btree_create();

    printf("先序遍历序列:");
    pre_order(t); 
    printf("\n");

    printf("中序遍历序列:");
    mid_order(t); 
    printf("\n");

    printf("后序遍历序列:");
    post_order(t); 
    printf("\n");

    printf("按层遍历序列:");
    level_order(t); 
    printf("\n");
    return 0;
}


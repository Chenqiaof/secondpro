#include "btree.h"
#include "linkqueue.h"


//创建二叉树
btree_pnode btree_create(void)
{
    btree_pnode t;
    datatype_bt ch;

    scanf("%c",&ch);

    if(ch == '#')
	t = NULL;
    else{
	//创建根节点
	t = (btree_pnode)malloc(sizeof(btree_node));
	if(NULL == t){
	    perror("malloc");
	    exit(1);
	}
	t->data = ch;
	//创建左子树
	t->lchild = btree_create();
	//创建右子树
	t->rchild = btree_create();
    }

    return t;
}

//先序遍历算法
void pre_order(btree_pnode t)
{
    if(t != NULL){
	//访问根节点
	printf("%c",t->data);
	//遍历左子树
	pre_order(t->lchild);
	//遍历右子树
	pre_order(t->rchild);
	
    }
}
//中序遍历算法
void mid_order(btree_pnode t)
{
    if(t != NULL){
	//遍历左子树
	mid_order(t->lchild);
	//访问根节点
	printf("%c",t->data);
	//遍历右子树
	mid_order(t->rchild);
	
    }
}
//后序遍历算法
void post_order(btree_pnode t)
{
    if(t != NULL){
	//遍历左子树
	post_order(t->lchild);
	//遍历右子树
	post_order(t->rchild);
	//访问根节点
	printf("%c",t->data);
	
    }
}

//按层遍历算法
void level_order(btree_pnode t)
{
    link_pqueue q;

    q = linkqueue_init();
    
    while(t != NULL){
	printf("%c",t->data);
	if(t->lchild != NULL)
	    linkqueue_in(q,t->lchild);
	if(t->rchild != NULL)
	    linkqueue_in(q,t->rchild);
	if(!linkqueue_isempty(q)){
	    linkqueue_out(q,&t);
	}else{
	    break;
	}
    }

}

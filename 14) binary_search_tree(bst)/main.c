#include<stdio.h>
#include<stdlib.h>

typedef struct tree_node* treeptr;
typedef struct tree_node {
    int data;
    treeptr lchild, rchild;
}tree;

int datalist[] = {12, 9, 19, 3, 5, 22, 10, 2};
int i;

treeptr root;

treeptr position(treeptr pt, int k)
{
    if (pt != NULL)
    {
        if (k < pt->data)
        {
            if (pt->lchild == NULL)
                return pt;
            else
                return position(pt->lchild, k);
        }
        else if (k > pt->data)
        {
            if (pt->rchild == NULL)
                return pt;
            else
                return position(pt->rchild, k);
        }
    }
    else
        return NULL;
}

void insertBST(int k)
{
    treeptr nodefound, newnode;
    nodefound = position(root, k);
    newnode = (treeptr)malloc(sizeof(tree));
    newnode->data = k;
    newnode->lchild = newnode->rchild = NULL;


    if (root == NULL)
        root = newnode;
    else
    {
        if (nodefound != NULL)
        {
            if (k < nodefound->data)
                nodefound->lchild = newnode;
            else
                nodefound->rchild = newnode;
        }
    }
}

void print(treeptr pt)
{
    if (pt == root)
        printf("data in BST : ");
    if (pt != NULL)
    {
        print(pt->lchild);
        printf("%d ", pt->data);
        print(pt->rchild);
    }
}

void inorderprint()
{
    print(root);
    puts("");
}

int main()
{
    printf("----- 12, 9, 19, 3, 5, 22, 10, 2 is inserted sequentially in BST -----\n");

    for (i = 0; i < 8; i++)
        insertBST(datalist[i]);

    inorderprint();

    return 0;
}

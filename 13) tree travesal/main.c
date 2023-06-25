#include <stdio.h>
#include <stdlib.h>

typedef struct tree *treeptr;
typedef struct tree{
    char data;
    treeptr lchild, rchild;
}tree;

typedef struct node *nodeptr;
typedef struct node{
    treeptr data;
    nodeptr link;
}node;

nodeptr rear = NULL;
nodeptr front = NULL;
treeptr root = NULL;

void visit(treeptr ptr){
    printf("%c ", ptr->data);
}

void preOrder(treeptr ptr){
    if(ptr != NULL){
        visit(ptr);
        preOrder(ptr->lchild);
        preOrder(ptr->rchild);
    }
}

void inOrder(treeptr ptr){
    if(ptr != NULL){
        inOrder(ptr->lchild);
        visit(ptr);
        inOrder(ptr->rchild);
    }
}

void postOrder(treeptr ptr){
    if(ptr != NULL){
        postOrder(ptr->lchild);
        postOrder(ptr->rchild);
        visit(ptr);
    }
}

void insertQ(treeptr item){
    nodeptr newp = (nodeptr)malloc(sizeof(node));
    if(newp == NULL)
        printf("Queue is full.\n");
    else{
        newp->data = item;
        newp->link = NULL;
        if(rear != NULL)
            rear->link = newp;
        rear = newp;
        if(front == NULL)
            front = newp;
    }
}

treeptr deleteQ(){
    nodeptr tmp;
    treeptr val;
    if(front==NULL)
        printf("Queue is empty.\n");
    else{
        tmp = front;
        val = tmp->data;
        front = front->link;
        free(tmp);
        return val;
    }
}

void levelOrder(treeptr ptr){
    if(ptr != NULL){
        visit(ptr);
        if(ptr->lchild != NULL)
            insertQ(ptr->lchild);
        if(ptr->rchild != NULL)
            insertQ(ptr->rchild);
        if(front != NULL)
            levelOrder(deleteQ());
    }
}


int main(){
    treeptr newp = NULL;

    root = (treeptr)malloc(sizeof(tree));
    root -> data = '/';
    root -> lchild = NULL;
    root -> rchild = NULL;

    newp = (treeptr)malloc(sizeof(tree));
    newp -> data = '*';
    newp -> lchild = NULL;
    newp -> rchild = NULL;
    root -> lchild = newp;

    newp = (treeptr)malloc(sizeof(tree));
    newp -> data = '+';
    newp -> lchild = NULL;
    newp -> rchild = NULL;
    root -> rchild = newp;

    newp = (treeptr)malloc(sizeof(tree));
    newp -> data = '+';
    newp -> lchild = NULL;
    newp -> rchild = NULL;
    root -> lchild -> lchild = newp;

    newp = (treeptr)malloc(sizeof(tree));
    newp -> data = '-';
    newp -> lchild = NULL;
    newp -> rchild = NULL;
    root -> lchild -> rchild = newp;

    newp = (treeptr)malloc(sizeof(tree));
    newp -> data = 'e';
    newp -> lchild = NULL;
    newp -> rchild = NULL;
    root -> rchild -> lchild = newp;

    newp = (treeptr)malloc(sizeof(tree));
    newp -> data = 'f';
    newp -> lchild = NULL;
    newp -> rchild = NULL;
    root -> rchild -> rchild = newp;

    newp = (treeptr)malloc(sizeof(tree));
    newp -> data = 'a';
    newp -> lchild = NULL;
    newp -> rchild = NULL;
    root -> lchild -> lchild -> lchild= newp;

    newp = (treeptr)malloc(sizeof(tree));
    newp -> data = 'b';
    newp -> lchild = NULL;
    newp -> rchild = NULL;
    root -> lchild -> lchild -> rchild = newp;

    newp = (treeptr)malloc(sizeof(tree));
    newp -> data = 'c';
    newp -> lchild = NULL;
    newp -> rchild = NULL;
    root -> lchild -> rchild -> lchild = newp;

    newp = (treeptr)malloc(sizeof(tree));
    newp -> data = 'd';
    newp -> lchild = NULL;
    newp -> rchild = NULL;
    root -> lchild -> rchild -> rchild = newp;

    printf("Pre-order (visit -> left -> right) \n");
    preOrder(root);
    printf("\n\n");

    printf("In-order (left -> visit -> right) \n");
    inOrder(root);
    printf("\n\n");

    printf("Post-order (left -> right -> visit) \n");
    postOrder(root);
    printf("\n\n");

    printf("Level-order [print with level(height)] basis\n");
    levelOrder(root);
    printf("\n\n");


    printf("\n");
    return 0;
}

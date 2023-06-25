#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode *treeptr;
typedef struct treeNode
{
    int data;
    int BF;
    treeptr lchild, rchild;
} treeNode;

treeptr root = NULL;
int rotationDone;
int findDepth(treeptr t);
void rotation(treeptr a, treeptr parent);
int insertBST(int key, treeptr t, treeptr parent);
treeptr findBiggest(treeptr t);
treeptr findSmallest(treeptr t);
deleteBST(int key, treeptr t, treeptr parent);
void inorder(treeptr pt);
void inorderPrint();
int ReCalc(treeptr t);
void Adjust(treeptr t, treeptr parent);
void insertData(int data, treeptr t, treeptr parent);
void ReAdjust();

int main()
{
    int numOfData = 16;
    int datalist[] = {20, 30, 15, 35, 32, 8, 10, 14, 3, 9, 5, 50, 60, 70, 46, 49};
    int i, n;

    printf("datalist: ");
    for (i=0; i<numOfData; i++)
        printf("%d ", datalist[i]);
    puts("");
    if (root == NULL)
    {
        root = (treeptr)malloc(sizeof(treeNode));
        root->data = datalist[0];
        root->lchild = NULL;
        root->rchild = NULL;
        root->BF = 0;
    }
    for (i=1; i<numOfData; i++)
        insertData(datalist[i], root, NULL);
    puts("");
    printf("delete %d\n", n=10);
    deleteBST(n, root, NULL);
    ReAdjust();
    inorderPrint();
    return 0;
}
int findDepth(treeptr t)
{
    int left, right;
    if (t == NULL)
        return 0;
    else
    {
        if (t->lchild != NULL && t->rchild != NULL)
        {
            left = 1+ findDepth(t->lchild);
            right = 1+ findDepth(t->rchild);
            if (left > right)
                return left;
            else
                return right;
        }
        if (t->lchild != NULL)
            return 1 + findDepth(t->lchild);
        else if (t->rchild != NULL)
            return 1 + findDepth(t->rchild);
        else
            return 1;
    }
}


void rotation(treeptr a, treeptr parent)
{
    int left, right;
    treeptr b, c;

    rotationDone = 1;
    if (a->BF == 2)
    {
        b = a->lchild;
        left = findDepth(b->lchild);
        right = findDepth(b->rchild);
        if (left > right)
        {
            printf("**LL rotation at node=%d\n", a->data);
            a->lchild = b->rchild;
            b->rchild = a;
            if (a != root)
            {
                if (parent->data < b->data)
                    parent->rchild = b;
                else
                    parent->lchild = b;
            }
            else
                root = b;
        }
        else
        {
            c = b->rchild;
            printf("**LR rotation at node=%d\n", a->data);
            a->lchild = c->rchild;
            b->rchild = c->lchild;
            c->lchild = b;
            c->rchild = a;
            if (a != root)
            {
                if (parent->data < c->data)
                    parent->rchild = c;
                else
                    parent->lchild = c;
            }
            else
                root = b;
        }
    }
    else
    {
        b = a->rchild;
        left = findDepth(b->lchild);
        right = findDepth(b->rchild);
        if (left > right)
        {
            c = b->lchild;
            printf("**RL rotation at node=%d\n", a->data);
            a->rchild = c->lchild;
            b->lchild = c->rchild;
            c->lchild = a;
            c->rchild = b;
            if (a != root)
            {
                if (parent->data < c->data)
                    parent->rchild = c;
                else
                    parent->lchild = c;
            }
            else
                root = c;
        }
        else
        {
            printf("**RR rotation at node=%d\n", a->data);
            a->rchild = b->lchild;
            b->lchild = a;
            if (a != root)
            {
                if (parent->data < b->data)
                    parent->rchild = b;
                else
                    parent->lchild = b;
            }
            else
                root = b;
        }
    }
}

int insertBST(int key, treeptr t, treeptr parent)
{
    treeptr newnode;
    int x;

    if (t == NULL)
    {
        newnode = (treeptr)malloc(sizeof(treeNode));
        newnode->data = key;
        newnode->lchild = NULL;
        newnode->rchild = NULL;
        newnode->BF = 0;
        if (parent->data > key)
        {
            parent->lchild = newnode;
            return 1;
        }
        else
        {
            parent->rchild = newnode;
            return -1;
        }
    }
    else
    {
        if (key < t->data)
        {
            x = insertBST(key, t->lchild, t);
            t->BF += x;
            if (t->BF == 2 && rotationDone == 0)
                rotation(t, parent);
        }
        else if (key > t->data)
        {
            x = insertBST(key, t->rchild, t);
            t->BF += x;
            if (t->BF == -2  && rotationDone == 0)
                rotation(t, parent);
        }
        if (t->BF != 0 && parent != NULL && parent->data > key)
            return 1;
        else if (t->BF != 0 && parent != NULL && parent->data < key)
            return -1;
        else
            return 0;
    }
}

treeptr findBiggest(treeptr t)
{
    treeptr temp = t;
    printf("find biggest in the left subtree\n");
    if (temp->rchild != NULL)
    {
        while (temp->rchild != NULL)
            temp = temp->rchild;
        return temp;
    }
    else
        return t;
}

treeptr findSmallest(treeptr t)
{
    treeptr temp = t;

    printf("find smallest in the right subtree\n");
    if (temp->lchild != NULL)
    {
        while (temp->lchild != NULL)
            temp = temp->lchild;
        return temp;
    }
    else
        return t;
}

deleteBST(int key, treeptr t, treeptr parent)
{
    if (t == NULL)
        printf("data %d not exist\n", key);
    else
    {
        if (key == t->data)
        {
            if (t->lchild != NULL && t->rchild != NULL)
            {
                int left, right, hold, x;
                treeptr temp;

                left = findDepth(t->lchild);
                right = findDepth(t->rchild);
                if (left > right)
                {
                    temp = findBiggest(t->lchild);
                    hold = temp->data;
                    x = deleteBST(temp->data, t->lchild, t);
                }
                else
                {
                    temp = findSmallest(t->rchild);
                    hold = temp->data;
                    x = deleteBST(temp->data, t->rchild, t);
                }
                t->data = hold;
            }
            else if (t->lchild != NULL)
            {
                if (parent->data > key)
                    parent->lchild = t->lchild;
                else
                    parent->rchild = t->lchild;
                free(t);
            }
            else if (t->rchild != NULL)
            {
                if (parent->data > key)
                    parent->lchild = t->rchild;
                else
                    parent->rchild = t->rchild;
                free(t);
            }
            else
            {
                if (parent->data > key)
                    parent->lchild = NULL;
                else
                    parent->rchild = NULL;
                free(t);
            }
            ReCalc(parent);
        }
        else if (key < t->data)
            deleteBST(key, t->lchild, t);
        else
            deleteBST(key, t->rchild, t);
    }
}

void inorder(treeptr pt)
{
    if (pt!= NULL)
    {
        inorder(pt->lchild);
        printf("%d BF:%d   ", pt->data, pt->BF);
        inorder(pt->rchild);
    }
}

void inorderPrint()
{
    inorder(root);
    puts("");
}

int ReCalc(treeptr t)
{
    int left, right, diff;

    if (t != NULL)
    {
        if (t->lchild != NULL && t->rchild != NULL)
        {
            left = 1+ ReCalc(t->lchild);
            right = 1 + ReCalc(t->rchild);
            diff = left - right;
            t->BF = diff;
            if (left > right)
                return left;
            else
                return right;
        }
        else if (t->lchild != NULL && t->rchild == NULL)
        {
            left = 1 + ReCalc(t->lchild);
            t->BF = left;
            return left;
        }
        else if (t->rchild != NULL && t->lchild == NULL)
        {
            right = 1 + ReCalc(t->rchild);
            t->BF = -right;
            return right;
        }
        else
        {
            t->BF = 0;
            return 0;
        }
    }
}

void Adjust(treeptr t, treeptr parent)
{
    if (t != NULL)
    {
        if (t->BF == 2 | t->BF == -2)
            rotation(t, parent);
        else
        {
            Adjust(t->lchild, t);
            Adjust(t->rchild, t);
        }
    }
}

void insertData(int data, treeptr t, treeptr parent)
{
    printf("insert data %d\n", data);
    rotationDone = 0;
    insertBST(data, t, parent);
    ReCalc(root);
    inorderPrint();
}

void ReAdjust()
{
    rotationDone = 0;
    Adjust(root, NULL);
    ReCalc(root);
}

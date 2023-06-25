#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tree_node* treeptr;
typedef struct tree_node {
    char id;
    char name[10];
    treeptr lchild, rsibling;
}tree_node;

treeptr root, current_node;

void insertLCRS(char aname[], char newid)
{
    treeptr newnode, temp;
    newnode = (treeptr)malloc(sizeof(tree_node));
    newnode->id = newid;
    strcpy(newnode->name, aname);
    newnode->lchild = newnode->rsibling = NULL;
    if (current_node->lchild == NULL)
        current_node->lchild = newnode;
    else {
        temp = current_node->lchild;
        while (temp->rsibling != NULL)
            temp = temp->rsibling;
        temp->rsibling = newnode;
    }
}

int change_directory(treeptr t, char dname[])
{
    int found = 0;
    if (t != NULL)
    {
        if (t->id == 'd')
        {
            if (strcmp(t->name, dname) == 0)
            {
                current_node = t;
                return 1;
            }
            else
            {
                found = change_directory(t->lchild, dname);
                if (!found)
                    return change_directory(t->rsibling, dname);
                else
                    return 1;
            }
        }
        else
            return change_directory(t->rsibling, dname);
    }
    else
        return 0;
}

void change_folder(char dname[])
{
    int found = 0;
    found = change_directory(root, dname);
    if (!found)
        printf("%s : 해당 폴더는 존재하지 않습니다\n", dname);
}

void preorder(treeptr t)
{
    if (t != NULL)
    {
        printf("%s ", t->name);
        preorder(t->lchild);
        preorder(t->rsibling);
    }
}

void preorderprint()
{
    preorder(root);
    printf("\n");
}

void free_directory(treeptr t)
{
    if (t != NULL)
    {
        free_directory(t->rsibling);
        free_directory(t->lchild);
        free(t);
    }
}

void deleteLCRS(char dname[], char mkid)
{
    int flag = 0;
    treeptr before = current_node;
    treeptr t = current_node->lchild;

    while ((t != NULL && (strcmp(t->name, dname) != 0)))
    {
        before = t;
        t = t->rsibling;

    }

    if (flag == 0 ){
        if (t == NULL || t->id != 'f')
            printf("%s : 해당 파일이 존재하지 않습니다\n", dname);
        else
        {
            if (before == current_node)
                before->lchild = t->rsibling;
            else
                before->rsibling = t->rsibling;
            free(t);
        }

        flag = 1;
    }

    if (flag== 0) {
        if (t == NULL || t->id != 'd')
            printf("%s : 해당 폴더가 존재하지 않습니다\n", dname);
        else
        {
            if (t->lchild != NULL)
                free_directory(t->lchild);
            if (before == current_node)
                before->lchild = t->rsibling;
            else
                before->rsibling = t->rsibling;
            free(t);
        }
    }

}

void main()
{
   root = (treeptr)malloc(sizeof(tree_node));
   root->id = 'd';
   strcpy(root->name, "root");
   root->lchild = root->rsibling = NULL;
   current_node = root;
   insertLCRS("bskim", 'd');
   preorderprint();
   change_folder("bskim");
   insertLCRS("homework1", 'f');
   preorderprint();
   insertLCRS("homework2", 'f');
   preorderprint();
   insertLCRS("project", 'd');
   preorderprint();
   change_folder("project");
   insertLCRS("program1", 'f');
   preorderprint();
    deleteLCRS("homework1", 'f');
   preorderprint();
   deleteLCRS("project", 'd');
   preorderprint();
   change_folder("root");
   insertLCRS("yslee", 'd');
   preorderprint();
   change_folder("yslee");
   insertLCRS("mylab", 'f');
   insertLCRS("dongguk", 'f');
   insertLCRS("information", 'f');
   preorderprint();
   deleteLCRS("information", 'f');
   preorderprint();
   change_folder("yskim");
}

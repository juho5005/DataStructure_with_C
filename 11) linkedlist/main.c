#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct node *nodeptr;
typedef struct node
{
   int data;
   nodeptr link;
}node;

nodeptr head=NULL;

void insert(int k)
{
    nodeptr newp, prev;
    if(head==NULL)
    {
        head = (nodeptr)malloc(sizeof(node));
        head -> data = k;
        head -> link = NULL;

    }
    else
    {
        nodeptr lead = head;
        while(lead != NULL && lead->data < k)
        {
            prev = lead;
            lead = lead -> link;
        }
        newp = (nodeptr)malloc(sizeof(node));
        newp -> data = k;
        if(head == lead)
        {
            newp -> link = lead;
            head = newp;
        }

        else
        {
            newp -> link = lead;
            prev -> link = newp;
        }
    }
}

void deletem(int m)
{
    nodeptr prev;
    nodeptr lead = head;
    if(head == NULL)
        printf("Empty\n");
    else
    {
        while(lead != NULL && lead->data != m)
        {
            prev = lead;
            lead = lead -> link;
        }
        if(lead == NULL)
            printf("No Data for %d\n",m);
        else
        {
            if(head == lead)
                head = lead -> link;
            else
                prev -> link = lead -> link;

        }
    }

}
void PrintMember()
{
    nodeptr temp = head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp = temp->link;
    }
    puts("");

}

int main()
{
    // �Է��ؾ� �� ������ ���
    int inputs[8] = {99, 202, 33, 44, 5, 78, 97, 100};
    int i;

    // �Է��ؾ��� �����͸� linked list�� ����
    for (i=0; i<8; i++) {
        insert(inputs[i]);
    }
    // �����͸� linked list�� ������ �� �ʱ� ������ ���
    printf("----- �����͸� linked list�� ������ �� �ʱ� ���� -----\n");
    PrintMember();

    // ������ 5�� ���� �� ���
    deletem(5);
    printf("\n----- ������ 5�� ������ �� ��� -----\n");
    PrintMember();

    deletem(44);
    printf("\n----- ������ 44�� ������ �� ��� -----\n");
    PrintMember();

    deletem(202);
    printf("\n----- ������ 202�� ������ �� ��� -----\n");
    PrintMember();
}

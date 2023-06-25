#include <stdio.h>
#include <stdlib.h>

typedef struct node *nodeptr;
typedef struct node{
    char data;
    nodeptr link;
}node;

nodeptr top = NULL;

void push(char alpha)
{
    nodeptr newp = (nodeptr)malloc(sizeof(node));
    newp -> data = alpha;
    newp -> link = top;
    top = newp;
}

void printstack()
{
    nodeptr temp = top;

    while(temp!=NULL)
    {
        printf("%c ", temp -> data);
        temp = temp -> link;
    }
    printf("\n");
}

char pop()
{
    nodeptr temp;
    char alpha;
    if(top == NULL)
        printf("������ ����ֽ��ϴ�.\n");
    else
    {
        temp = top;
        alpha = temp -> data;
        top = top -> link;
        free(temp);
        return alpha;
    }
}

int main()
{
    printf("----- ������ Ư�� �� ����� ������ ������ ����� �ǹ��ϰ� �ڵ带 �ۼ��߽��ϴ�.-----\n\n");
    push('a');
    push('b');
    push('c');
    push('d');
    push('e');
    printf("----- ���ĺ� 5�� (a,b,c,d,e)�� push �� ���-----\n");
    printstack();

    // 2���� pop ����
    printf("----- pop()�� 2�� �����ϰ� �� �� ������ ���------\n");
    pop();
    pop();
    printstack();

    // 2���� push ����
    printf("----- push('x'), push('y')�� ������ �� ���------\n");
    push('x');
    push('y');
    printstack();
    return 0;
}

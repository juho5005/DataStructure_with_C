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
        printf("스택이 비어있습니다.\n");
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
    printf("----- 스택의 특성 상 출력의 왼쪽이 스택의 상단을 의미하게 코드를 작성했습니다.-----\n\n");
    push('a');
    push('b');
    push('c');
    push('d');
    push('e');
    printf("----- 알파벳 5개 (a,b,c,d,e)를 push 후 출력-----\n");
    printstack();

    // 2번의 pop 과정
    printf("----- pop()을 2번 적용하고 난 후 스택을 출력------\n");
    pop();
    pop();
    printstack();

    // 2번의 push 과정
    printf("----- push('x'), push('y')를 실행한 후 출력------\n");
    push('x');
    push('y');
    printstack();
    return 0;
}

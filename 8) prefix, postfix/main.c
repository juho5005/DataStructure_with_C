#include<stdio.h>
#include<string.h>
#define SIZE 1000

char inputs[] = { 'a', '+', 'b', '*', 'c', '-', 'd'};
int top = -1;

void push(int item)
{
    if (top < SIZE)
        inputs[++top] = item;
}

int pop()
{
    if (top >= 0)
        return inputs[top--];
}

int main(void)
{
    int i = 0;
    char token;

    while (inputs[i] != NULL)
    {
        token = inputs[i];

        if (token == '*') {
            push(token);

        }
        else if (token == '+') {

            push(token);
        }

        else if (token == '-') {
            printf("%c ", pop());

            push(token);
        }

        else if (token == '/') {
            push(token);
        }
        else
            printf("%c ", token);
        i++;
    }

    for (i = top; i >= 0; i--) {
        printf("%c ", inputs[i]);
    }

    return 0;
}

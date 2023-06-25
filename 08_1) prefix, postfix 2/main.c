#include<stdio.h>
#include<string.h>
#define SIZE 1000

char inputs[] = { '8', '2', '3', '*', '4', '-', '+', '2', '/' };
int stack[SIZE];

int top = -1;

int stack_top = -1;

void push(int item)
{
        stack[++stack_top] = item;
}

int pop() {
    return stack[stack_top--];
}

int main(void)
{
    int i = 0;

    int summation = 0;

    int first, second;
    char token;

    while (inputs[i] != NULL)
    {
        token = inputs[i];

        if (token != '+' && token != '-' && token != '*' && token != '/') {
            push(token - '0');
        }
        else {
            second = pop();
            first = pop();

            if (token == '+') {
                summation = (first + second);
                push(summation);
            }

            else if (token == '-') {
                summation = (first - second);
                push(summation);
            }

            else if (token == '*') {
                summation = (first * second);
                push(summation);
            }

            else {
                summation = (first / second);
                push(summation);
            }
        }

        i++;
    }

    printf("%d ", stack[0]);

    return 0;
}

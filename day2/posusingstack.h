#ifndef POSUSINGSTACK
#define POSUSINGSTACK
#include <stdio.h>
#define MAX 100
int top = -1;
int STACK[MAX];

int pop()
{
    if (top == -1)
    {
        printf("empty\n");
        return -127;
    }
    return STACK[top--];
}
void push(int data)
{
    if (top == MAX - 1)
    {
        printf("full\n");
        return;
    }
    STACK[++top] = data;
}

#endif
#include <stdio.h>
int top = -1;
#define MAX 100
int STACK[MAX];
void push(int data)
{
    if (top == MAX - 1)
    {
        printf("full\n");
        return;
    }
    STACK[++top] = data;
}
int pop()
{
    if (top == -1)
    {
        printf("empty\n");
        return __INT32_MAX__;
    }
    return STACK[top--];
}
void display()
{
    printf("Displaying: ");
    if (top == -1)
        printf("Uh oh looks like the stack is empty");
    for (int i = 0; i <= top; i++)
        printf("%d ", STACK[i]);
    printf("\n");
}
int main(int argc, char const *argv[])
{
    push(10);
    push(20);
    push(30);
    display();
    printf("\npopped %d\n", pop());
    display();
    push(40);
    display();
    return 0;
}

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
        printf("Queue is empty\n");
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
    int CASE = 10;
    while (CASE != 4)
    {
        printf("Choose an option \n1)push\n2)pop\n3)display\n4)exit\n");
        scanf("%d", &CASE);
        if (CASE == 1)
        {
            printf("Enter the data to push : ");
            int data;
            scanf("%d", &data);
            push(data);
        }
        else if (CASE == 2)
            printf("Dequeued %d\n", pop());
        else if (CASE == 3)
            display();
    }
    return 0;
}

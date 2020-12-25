#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *head = NULL;
node *tail = NULL;

void push(int data)
{
    node *temp = malloc(sizeof(node));
    temp->data = data;
    if (!head)
    {
        head = temp;
        tail = temp;
        tail->next = head;
        head->next = temp;
    }
    else
    {
        temp->next = head;
        head = temp;
        tail->next = temp;
    }
}
int pop()
{
    if (!head)
    {
        printf("stack underflow\n");
        return -(__INT32_MAX__ - 1);
    }
    node *toFree = head;
    int toReturn = head->data;
    head = head->next;
    tail->next = head;
    free(toFree);
    return toReturn;
}

void display()
{
    node *temp = head;
    printf("Displaying\n");
    if (temp)
        printf("%d ", temp->data);
    else
        printf("Stack is empty");
    while (temp != tail)
    {
        printf("%d ", temp->next->data);
        temp = temp->next;
    }
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
            printf("popped %d\n", pop());
        else if (CASE == 3)
            display();
    }
    return 0;
}
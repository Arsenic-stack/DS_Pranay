#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *head = NULL;
node *tail = NULL;

void enqueue(int data)
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
        tail->next = temp;
        tail = temp;
    }
}
int dequeue()
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
    printf("%d ", temp->data);
    while (temp != tail)
    {
        printf("%d ", temp->next->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    for (int i = 0; i < 4; i++)
        enqueue(i * 10);
    display();
    printf("%d dequeued\n", dequeue());
    enqueue(69);
    display();
    return 0;
}

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
    struct node *temp = malloc(sizeof(node));
    temp->data = data;
    if (!head)
        head = tail = temp;
    else
    {
        tail->next = temp;
        tail = temp;
    }
}
int dequeue()
{
    if (!head)
    {
        printf("Queue is empty nothing to dequeue\n");
        return -(__INT16_MAX__);
    }
    else
    {
        node *toFree = head;
        int toReturn = head->data;
        head = head->next;
        return toReturn;
    }
}

void display()
{
    node *temp = head;
    printf("Displaying : ");
    while (temp)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main(int argc, char const *argv[])
{
    for (int i = 0; i < 4; i++)
        enqueue(i * 10);
    display();
    printf("dequeued %d\n", dequeue());
    for (int i = 4; i < 8; i++)
        enqueue(i * 10);
    display();
    printf("dequeued %d\n", dequeue());
    display();
    return 0;
}

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
        free(toFree);
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
    int CASE = 10;
    while (CASE != 4)
    {
        printf("Choose an option \n1)enqueue\n2)dequeue\n3)display\n4)exit\n");
        scanf("%d", &CASE);
        if (CASE == 1)
        {
            printf("Enter the data to push : ");
            int data;
            scanf("%d", &data);
            enqueue(data);
        }
        else if (CASE == 2)
            printf("Dequeued %d\n", dequeue());
        else if (CASE == 3)
            display();
    }
    return 0;
}

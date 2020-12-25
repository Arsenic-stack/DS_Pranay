////////////////////////
////// error in code while dequeuing empty queue
//free(): double free detected in tcache 2
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
    if (head == NULL)
    {
        printf("stack underflow\n");
        return -(__INT32_MAX__ - 1);
    }

    node *toFree = head;
    int toReturn = head->data;
    head = NULL;
    head = toFree->next;
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
    int CASE = 10;
    while (CASE != 4)
    {
        printf("Choose an option \n1)enqueue\n2)dequeue\n3)display\n4)exit\n");
        scanf("%d", &CASE);
        if (CASE == 1)
        {
            printf("Enter the data to enqueue : ");
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

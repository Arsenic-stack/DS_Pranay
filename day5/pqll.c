#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    int priority;
    struct node *next;
} node;

node *head = NULL;

void insert(int data, int priority)
{
    node *temp = malloc(sizeof(node));
    temp->data = data;
    temp->priority = priority;
    if (!head)
    {
        head = temp;
        return;
    }
    if (head->priority < priority)
    {
        temp->next = head;
        head = temp;
    }
    else
    {
        node *traverse = head;
        while (traverse->next && (priority < traverse->priority))
            traverse = traverse->next;
        temp->next = traverse->next;
        traverse->next = temp;
    }
}
int removeNode()
{
    if (!head)
    {
        node *temp=head;
        head=head->next;
        free(head);
    }
    int toReturn = head->data;
    node *toFree = head;
    head = head->next;
    free(toFree);
    return toReturn;
}
void display()
{
    node *temp = head;
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
        printf("Choose an option \n1)insert\n2)remove\n3)display\n4)exit\n");
        scanf("%d", &CASE);
        if (CASE == 1)
        {
            printf("Enter the data to push and priority : ");
            int data,priority;
            scanf("%d %d", &data,&priority);
            insert(data,priority);
        }
        else if (CASE == 2)
            printf("Dequeued %d\n", removeNode());
        else if (CASE == 3)
            display();
    }
    return 0;
}

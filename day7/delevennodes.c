#include <stdio.h>
#include <stdlib.h>
#define null NULL
typedef struct node
{
    int data;
    struct node *next;
} node;

node *head;
node *tail;

void insert(int data)
{
    node *link = malloc(sizeof(node));
    link->data = data;
    if (head == null)
    {
        head = link;
        tail = link;
    }
    else
    {
        node *temp = tail;
        tail->next = link;
        tail = tail->next;
    }
}

void print()
{
    node *temp = head;
    while (temp)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void removeven(node *temp)
{
    if (temp == NULL)
        return;
    struct node *toFree = temp->next;
    if (toFree == NULL)
        return;
    temp->next = toFree->next;
    free(toFree);
    removeven(temp->next);
}
void tests()
{
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);
    insert(6);
    insert(7);
    print();
    removeven(head);
    print();
    exit(0);
}

int main(int argc, char const *argv[])
{
    // tests();
    int CASE = 10;
    while (CASE != 3)
    {
        printf("Choose an option \n1)insert\n2)display\n3)exit\n");
        scanf("%d", &CASE);
        if (CASE == 1)
        {
            printf("Enter the data insert : ");
            int data;
            scanf("%d", &data);
            insert(data);
        }
        else if (CASE == 2)
            print();
        else if (CASE == 3)
            removeven(head);
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} node;

node *head = NULL;
node *tail = NULL;
int length = -1;
void insertAny(int data, int pos)
{
    if (length == -1)
    {
        node *temp = malloc(sizeof(node));
        temp->data = data;
        head = temp;
        tail = head;
        head->next = tail;
        tail->next = head;
        length = 1;
        return;
    }
    if (length < pos)
    {
        printf("Cant insert , list length is %d but the position you wanted to insert was %d", length, pos);
        return;
    }
    node *temp = malloc(sizeof(node));
    temp->data = data;
    if (pos == 0)
    {
        temp->next = head;
        head = temp;
        tail->next = head;
    }
    else
    {
        node *traverse = head;
        while ((pos > 1) && (traverse->next != head))
        {
            traverse = traverse->next;
            pos--;
        }
        temp->next = traverse->next;
        traverse->next = temp;
    }
    length++;
}
void deleteAny(int pos)
{
    if ((length-1 < pos) || (length == 0))
    {
        printf("Cant delete , list length is %d but the position you wanted to delete was %d\n", length, pos);
        return;
    }
    if (pos == 0)
    {
        if (length == 1)
        {
            printf("deleting %d\n", head->data);
            free(head);
            head = NULL;
            length = -1;
            return;
        }

        node *toFree = head;
        printf("deleting %d\n", head->data);
        head = head->next;
        tail->next = head;
        free(toFree);
        length = -1;
    }
    else
    {

        node *traverse = head;
        while ((pos > 1) && (traverse->next != head))
        {
            traverse = traverse->next;
            pos--;
        }
        printf("deleting %d\n", traverse->next->data);
        if (traverse->next->next)
            traverse->next = traverse->next->next;
        else
        {
            tail = traverse->next;
            tail->next = head;
        }
    }
    length--;
}
void display()
{
    node *traverse = head;
    if (!traverse)
    {
        printf("\nList is empty\n");
        return;
    }
    while (traverse->next != head)
    {
        printf("%d ", traverse->data);
        traverse = traverse->next;
    }
    if (traverse)
        printf("%d", traverse->data);

    printf("\n");
}

int main()
{
    int CASE = 10;
    while (CASE != 4)
    {
        printf("Choose an option \n1)insertany\n2)deleteany\n3)display\n4)exit\n");
        scanf("%d", &CASE);
        if (CASE == 1)
        {
            printf("Enter the data and position to insert : ");
            int data, pos;
            scanf("%d %d", &data, &pos);
            insertAny(data, pos);
        }
        else if (CASE == 2)
        {
            printf("Enter position to delete : ");
            int pos;
            scanf("%d", &pos);
            deleteAny(pos);
        }
        else if (CASE == 3)
            display();
    }

    return 0;
}
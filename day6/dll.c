#include <stdio.h>
#include <stdlib.h>
void tests();
typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} node;

node *head = NULL;
node *tail = NULL;
int length = -1;
void insertAny(int data, int pos)
{
    if (length == -1)
        length = 0;
    if (length < pos)
    {
        printf("Cant insert , list length is %d but the position you wanted to insert was %d", length, pos);
        return;
    }
    node *temp = malloc(sizeof(node));
    temp->data = data;
    if (pos == 0)
    {
        if (head)
            head->prev = temp;
        temp->next = head;
        head = temp;
    }
    else
    {
        node *traverse = head;
        while ((pos > 1) && (traverse->next))
        {
            traverse = traverse->next;
            pos--;
        }
        temp->next = traverse->next;
        traverse->next = temp;
        temp->prev = traverse;
        while (traverse->next)
            traverse = traverse->next;
        tail = traverse;
    }
    length++;
    if (length == 1)
        tail = head;
}
void deleteAny(int pos)
{
    if ((length - 1 < pos) || (length == 0))
    {
        printf("Cant delete , list length is %d but the position you wanted to delete was %d\n", length, pos);
        return;
    }
    if (pos == 0)
    {
        node *toFree = head;
        printf("deleting %d\n", head->data);
        if (head->next)
            head->next->prev = NULL;
        head = head->next;
        free(toFree);
        if (length == 1)
            length--;
    }
    else
    {
        node *traverse = head;
        for (int i = 0; i < pos; i++)
            traverse = traverse->next;
        printf("deleting %d\n", traverse->data);
        node *toFree = traverse;
        if (pos == length - 1)
            tail = traverse->prev;
        if (traverse->prev)
            traverse->prev->next = traverse->next;
        if (traverse->next)
            traverse->next->prev = traverse->prev;
        while (traverse->next)
            traverse = traverse->next;
        free(toFree);
    }
    length--;
}
void display()
{
    printf("Displaying : ");
    node *traverse = head;
    while (traverse)
    {
        printf("%d ", traverse->data);
        traverse = traverse->next;
    }
    printf("\n");
}
void displayBack()
{
    printf("Displaying : ");
    node *traverse = tail;
    while (traverse != head)
    {
        printf("%d ", traverse->data);
        traverse = traverse->prev;
    }
    printf("%d ", traverse->data);
    printf("\n");
}
int main()
{
    // tests();
    int CASE = 10;
    while (CASE != 5)
    {
        printf("Choose an option \n1)insertany\n2)deleteany\n3)display\n4)display back\n5)exit");
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
        else if (CASE == 4)
            displayBack();
    }
    return 0;
}

void tests()
{
    insertAny(10, 0);
    insertAny(20, 1);
    insertAny(30, 2);
    insertAny(40, 3);
    display();
    displayBack();
    deleteAny(3);
    display();
    displayBack();
    deleteAny(0);
    insertAny(50, 2);
    display();
    displayBack();
    exit(0);
}
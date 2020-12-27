#include <stdio.h>
#include <stdlib.h>
#define null NULL
void tests();
typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} node;

node *head = null;
node *tail = null;
void insert(int data)
{
    node *temp = malloc(sizeof(node));
    temp->data = data;
    if (head == null)
    {
        temp->next = head;
        head = temp;
        tail = temp;
    }
    else
    {
        node *traverse = head;
        if (data > head->data)
        {
            temp->next = head;
            head->prev = temp;
            head = temp;
        }

        else
        {
            while (traverse->next && traverse->next->data > data)
                traverse = traverse->next;
            temp->next = traverse->next;
            temp->prev = traverse;
            if (traverse->next)
                traverse->next->prev = temp;
            traverse->next = temp;
            while (traverse->next)
                traverse = traverse->next;
            tail = traverse;
        }
    }
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
void displayBack()
{
    node *temp = tail;
    while (temp)
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    // tests();
    int CASE = 10;
    while (CASE != 4)
    {
        printf("Choose an option \n1)insert\n2)display\n3)display back\n4)exit");
        scanf("%d", &CASE);
        if (CASE == 1)
        {
            printf("Enter the data insert : ");
            int data;
            scanf("%d", &data);
            insert(data);
        }
        else if (CASE == 2)
            display();
        else if (CASE == 3)
            displayBack();
    }
    return 0;
}
// void tests()
// {
//     insert(10);
//     insert(200);
//     insert(35);
//     insert(1);
//     insert(56);
//     display();
//     displayBack();
//     exit(0);
// }
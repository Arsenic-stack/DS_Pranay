#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} node;

node *head = NULL;
void push(int data)
{
    node *temp = malloc(sizeof(node));
    temp->data = data;
    if (!head)
        head = temp;
    else
        (temp->next = head) && (head = temp);
}
void display()
{
    node *temp = head;
    printf("\n Displaying: ");
    while (temp)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void reverse()
{
    node *prev = NULL;
    node *curr = head;
    node *next = NULL;
    while (curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

int main(int argc, char const *argv[])
{
    for (int i = 0; i < 4; i++)
        push(i * 10);
    for (int i = 4; i < 8; i++)
        push(i * 10);
    display();
    reverse();
    display();
    return 0;
}

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
    temp->data=data;
    if (!head)
        head = temp;
    else
        (temp->next = head) && (head = temp);
}

int pop()
{
    if (!head)
    {
        printf("stack is empty");
        return -(__INT16_MAX__ - 1);
    }
    else
    {
        int toreturn = head->data;
        node *tofree = head;
        head = head->next;
        free(tofree);
        return toreturn;
    }
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
}

int main(int argc, char const *argv[])
{
    for (int i = 0; i < 4; i++)
        push(i * 10);
    display();
    printf("\npopped %d", pop());
    for (int i = 4; i < 8; i++)
        push(i * 10);
    display();
    return 0;
}

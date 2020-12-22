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
    int CASE = 10;
    while (CASE != 4)
    {
        printf("Choose an option \n1)push\n2)pop\n3)display\n4)exit\n");
        scanf("%d", &CASE);
        if (CASE == 1)
        {
            printf("Enter the data to push : ");
            int data;
            scanf("%d", &data);
            push(data);
        }
        else if (CASE == 2)
            printf("popped %d\n", pop());
        else if (CASE == 3)
            display();
    }
    return 0;
}

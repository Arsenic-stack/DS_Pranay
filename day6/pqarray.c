#include <stdio.h>
#include <stdlib.h>
#define MAX 20

int rear = -1;
int front = -1;
int arr[MAX];

int isempty()
{
    return (front == -1 || front > rear) ? 1 : 0;
}

int isfull()
{
    return (rear == MAX - 1) ? 1 : 0;
}

void enqueue(int data)
{
    if (isfull())
        printf("\nQueue Overflow\n");
    if (front == -1)
        front = 0;
    int j = rear;
    while (j >= 0 && data < arr[j])
    {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = data;
    rear++;
}

int dequeue()
{
    if (isempty())
    {
        printf("\nQueue Unerflow\n");
        front = -1;
        rear = -1;
    }
    int data = arr[front++];
    return data;
}

void display()
{
    int i = 0;
    if (isempty())
    {
        printf("\nQueue Underflow\n");
    }
    else
    {
        printf("\nThe elements are : ");
        for (i = front; i <= rear; i++)
        {
            printf("%d ", arr[i]);
        }
    }
}

int main()
{
    int x, ch;
    while (1)
    {
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Display");
        printf("\nAny other number to exit");
        printf("\nEnter your choice : ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("\nEnter the element to be inserted : ");
            scanf("%d", &x);
            enqueue(x);
            break;
        case 2:
            printf("\nThe element being deleted is : %d\n", dequeue());
            break;
        case 3:
            display();
            break;
        default:
            exit(0);
        }
    }
    return 0;
}
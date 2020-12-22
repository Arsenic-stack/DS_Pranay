#include <stdio.h>
int front = -1, rear = -1;
#define MAX 5
int QUEUE[MAX];

void enq(int data)
{
    if (front == -1 && rear == -1)
        (QUEUE[++front] = data) && ++rear;
    else if ((rear + 1) % MAX == front)
        printf("Queue is full\n");
    else
    {
        rear = (rear + 1) % MAX;
        QUEUE[rear] = data;
    }
}
int deq()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue underflow");
        return -(__INT16_MAX__);
    }
    else if (front == rear)
    {
        int toReturn = QUEUE[rear];
        front = -1;
        rear = -1;
        return toReturn;
    }
    int toReturn = QUEUE[front];
    front = (front + 1) % MAX;
    return toReturn;
}
void display()
{
    if (front == -1)
    {
        printf("\nQueue is Empty");
        return;
    }
    printf("\nElements in Circular Queue are: ");
    if (rear >= front)
    {
        for (int i = front; i <= rear; i++)
            printf("%d ", QUEUE[i]);
    }
    else
    {
        for (int i = front; i < MAX; i++)
            printf("%d ", QUEUE[i]);
        for (int i = 0; i <= rear; i++)
            printf("%d ", QUEUE[i]);
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
            enq(data);
        }
        else if (CASE == 2)
            printf("Dequeued %d\n", deq());
        else if (CASE == 3)
            display();
    }

    return 0;
}

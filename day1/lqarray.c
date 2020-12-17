#include <stdio.h>
int front = -1, rear = -1;
#define MAX 100
int QUEUE[MAX];

void enq(int data)
{
    if (front == -1 && rear == -1)
        (QUEUE[++front] = data) && ++rear;
    else if ((rear+1)<MAX)
        QUEUE[++rear] = data;
    else 
        printf("Queue is full\n");
}
int deq()
{
    if (front == -1 && rear == -1)
        return -(__INT16_MAX__);
    return QUEUE[front++];
}
void display()
{
    printf("Displaying : ");
    for (int i = front; i <= rear; i++)
        printf("%d ", QUEUE[i]);
    printf("\n");
}
int main(int argc, char const *argv[])
{
    enq(10);
    enq(20);
    enq(30);
    display();
    printf("\ndequeued %d \n", deq());
    display();
    enq(40);
    enq(50);
    enq(60);
    enq(70);
    printf("\ndequeued %d \n", deq());
    display();
    return 0;
}

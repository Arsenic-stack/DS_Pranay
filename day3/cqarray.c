#include <stdio.h>
int front = -1, rear = -1;
#define SIZE 10
int CQUEUE[100];
int isFull()
{
  if ((front == rear + 1) || (front == 0 && rear == SIZE - 1))
    return 1;
  return 0;
}
int isEmpty()
{
  if (rear == -1)
    return -1;
  return 0;
}
void enq(int data)
{
  if (isFull())
  {
    printf("stack overflow");
    return;
  }

  if (front == -1)
    front++;
  rear = (rear + 1) % SIZE;
  CQUEUE[rear] = data;
}
int deq()
{
  if (isEmpty())
  {
    return -(__INT16_MAX__ - 1);
  }
  int toReturn = CQUEUE[front];
  front = (++front) % SIZE;
  return toReturn;
}

void display()
{
  printf("\nDisplaying : ");
  if (isEmpty())
    printf("empty queue");

  for (int i = front; i <= rear; i = (i + 1) % SIZE)
    printf("%d ", CQUEUE[i]);
}

int main(int argc, char const *argv[])
{
  for (int i = 0; i < 4; i++)
    enq(i * 10);
  display();
  printf("\ndequeued %d", deq());
  for (int i = 4; i < 8; i++)
    enq(i * 10);
  display();
  return 0;
}

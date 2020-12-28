#include <stdio.h>
int front = -1, rear = -1;
#define SIZE 5
int CQUEUE[SIZE];
int isFull()
{
  if ((rear == (front - 1) % (SIZE - 1)) || (front == 0 && rear == SIZE - 1))
    return 1;
  return 0;
}
void enq(int data)
{
  if (isFull())
  {
    printf("stack overflow");
    return;
  }
  else if (front == -1) /* Insert First Element */
  {
    front = rear = 0;
    CQUEUE[rear] = data;
  }
  else if (rear == SIZE - 1 && front != 0)
  {
    rear = 0;
    CQUEUE[rear] = data;
  }
  else
  {
    rear++;
    CQUEUE[rear] = data;
  }
}
int deq()
{
  if (front == -1)
  {
    printf("\nQueue is Empty");
    return -(__INT32_MAX__ - 1);
  }
  int data = CQUEUE[front];
  CQUEUE[front] = -1;
  if (front == rear)
  {
    front = -1;
    rear = -1;
  }
  else if (front == SIZE - 1)
    front = 0;
  else
    front++;
  return data;
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
      printf("%d ", CQUEUE[i]);
  }
  else
  {
    for (int i = front; i < SIZE; i++)
      printf("%d ", CQUEUE[i]);

    for (int i = 0; i <= rear; i++)
      printf("%d ", CQUEUE[i]);
  }
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

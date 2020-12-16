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
int isEmpty(){
    ///if(top)
    // to be continued
}
#include "queue.h"
#include "stdio.h"

int main() {
  queue *q = AllocateQueue();
  printf("queue empty: %d \n", QueueEmpty(q));

  Enqueue(q, 1);
  Enqueue(q, 2);
  Enqueue(q, 3);
  Enqueue(q, 4);
  Enqueue(q, 5);
  Enqueue(q, 6);
  Enqueue(q, 7);

  printf("%d\n", Dequeue(q));
  printf("%d\n", Dequeue(q));

  Enqueue(q, 8);
  Enqueue(q, 9);

  printf("%d\n", Dequeue(q));
  printf("%d\n", Dequeue(q));
  printf("%d\n", Dequeue(q));
  printf("%d\n", Dequeue(q));
  printf("%d\n", Dequeue(q));
  printf("%d\n", Dequeue(q));
  printf("%d\n", Dequeue(q));

  printf("queue empty: %d \n", QueueEmpty(q));

  DeallocateQueue(q);

  return 0;
}
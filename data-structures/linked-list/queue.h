#include "linked-list.h"

typedef struct queue {
  linked_list *q;
} queue;

queue *AllocateQueue();
void DeallocateQueue(queue *queue);
int QueueEmpty(queue *queue);
void Enqueue(queue *queue, int x);
int Dequeue(queue *queue);
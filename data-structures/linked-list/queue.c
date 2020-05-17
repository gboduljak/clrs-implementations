#include "queue.h"
#include <stdlib.h>

queue *AllocateQueue() {
  queue *new = (queue *)malloc(sizeof(queue));
  new->q = AllocateLinkedList();
  return new;
}

void DeallocateQueue(queue *queue) {
  DellocateLinkedList(queue->q);
  free(queue);
}

int QueueEmpty(queue *queue) { return queue->q->length == 0; }

void Enqueue(queue *queue, int x) { ListInsert(queue->q, x); }

int Dequeue(queue *queue) {
  int x = queue->q->nil->prev->key;
  ListDelete(queue->q, queue->q->nil->prev);
  return x;
}
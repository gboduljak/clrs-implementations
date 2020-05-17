#include "queue.h"
#include <stdlib.h>

queue *AllocateQueue(int length)
{
  queue *new = (queue *)malloc(sizeof(queue));
  new->Q = malloc(sizeof(int) * length);
  new->head = 0;
  new->tail = 0;
  new->length = length;
  return new;
}

void DeallocateQueue(queue *queue)
{
  free(queue->Q);
  free(queue);
}

int QueueEmpty(queue *queue) { return (queue->head + 1) % queue->length == queue->tail; }
int QueueFull(queue *queue)
{
  return (queue->tail) % queue->length == queue->head;
}

void Enqueue(queue *queue, int x)
{
  queue->Q[queue->tail] = x;

  if (queue->tail == queue->length)
    queue->tail = 0;
  else
    queue->tail++;
}

int Dequeue(queue *queue)
{
  int x = queue->Q[queue->head];

  if (queue->head == queue->length)
    queue->head = 0;
  else
    queue->head++;

  return x;
}
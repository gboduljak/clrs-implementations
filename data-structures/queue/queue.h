typedef struct queue
{
  int *Q;
  int head;
  int tail;
  int length;
} queue;

queue *AllocateQueue(int length);
void DeallocateQueue(queue *queue);
int QueueEmpty(queue *queue);
int QueueFull(queue *queue);
void Enqueue(queue *queue, int x);
int Dequeue(queue *queue);
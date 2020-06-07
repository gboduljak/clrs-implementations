#include "priority-queue.h"
#include "priority_queue_element.h"

priority_queue *AllocateMinPq(int size);
void DestroyMinPq();

priority_queue *BuildMinPq(int *ids, int *keys, int input_size, int heap_size);
priority_queue_element *MinPqInsert(priority_queue *pq, int id, int key);
int MinPqLookupKey(priority_queue *pq, int id);
void MinPqDecreaseKey(priority_queue *pq, int i, int new_key);
priority_queue_element *MinPqExtractMin(priority_queue *pq);

#include "min-priority-queue.h"
#include "max-priority-queue.h"

#include <stdio.h>
#include <stdlib.h>

priority_queue *AllocateMinPq(int size) { return AllocateMaxPq(size); }
void DestroyMinPq(priority_queue *pq) { DestroyMaxPq(pq); }

priority_queue *BuildMinPq(int *ids, int *keys, int input_size, int heap_size) {
  int i = 0;
  for (i = 0; i < input_size; i++)
    keys[i] = -keys[i];
  return BuildMaxPq(ids, keys, input_size, heap_size);
}

priority_queue_element *MinPqInsert(priority_queue *pq, int id, int key) {
  priority_queue_element *element = MaxPqInsert(pq, id, -key);
  element->key = -element->key;
  return element;
}

int MinPqLookupKey(priority_queue *pq, int id) {
  return -MaxPqLookupKey(pq, id);
}

void MinPqDecreaseKey(priority_queue *pq, int i, int new_key) {
  MaxPqIncreaseKey(pq, i, -new_key);
}

priority_queue_element *MinPqExtractMin(priority_queue *pq) {
  priority_queue_element *min = MaxPqExtractMax(pq);
  min->key = -min->key;
  return min;
}
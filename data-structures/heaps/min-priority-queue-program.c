#include "max-priority-queue.h"
#include "min-priority-queue.h"

#include <stdio.h>
#include <stdlib.h>

int main() {
  int length;

  scanf("%d", &length);
  int i;

  int *ids = (int *)malloc(sizeof(int) * length);
  int *keys = (int *)malloc(sizeof(int) * length);

  for (i = 0; i < length; i++) {
    scanf("%d %d", &ids[i], &keys[i]);
  }

  priority_queue *pq = BuildMinPq(ids, keys, length, 100);

  MinPqInsert(pq, 12, 43);
  MinPqInsert(pq, 13, 54);
  MinPqInsert(pq, 14, 1);

  MinPqDecreaseKey(pq, 7, 0);
  MinPqDecreaseKey(pq, 7, 5);
  MinPqDecreaseKey(pq, 5, 2);

  MinPqDecreaseKey(pq, 4, 5);
  MinPqDecreaseKey(pq, 10, 5);
  MinPqDecreaseKey(pq, 4, 7);
  MinPqDecreaseKey(pq, 4, 8);

  for (i = 0; i < length + 3; i++) {
    priority_queue_element *el = MinPqExtractMin(pq);
    printf("id:%d key:%d\n", el->id, el->key);
  }

  DestroyMinPq(pq);
}
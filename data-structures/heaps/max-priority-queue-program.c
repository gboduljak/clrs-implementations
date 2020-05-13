#include "max-priority-queue.h"
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

  priority_queue *pq = BuildMaxPq(ids, keys, length, 100);

  MaxPqInsert(pq, 12, 43);
  MaxPqInsert(pq, 13, 54);
  MaxPqIncreaseKey(pq, 11, 30);
  MaxPqIncreaseKey(pq, 4, 28);

  for (i = 0; i < length; i++) {
    priority_queue_element *el = MaxPqExtractMax(pq);
    printf("id:%d key:%d\n", el->id, el->key);
  }

  DestroyMaxPq(pq);
}
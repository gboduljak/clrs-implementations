#include "max-priority-queue.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  int length;

  // scanf("%d", &length);
  int i;
  max_priority_queue *pq = AllocateMaxPq(100);

  // int *ids = (int *)malloc(sizeof(int) * length);
  // int *keys = (int *)malloc(sizeof(int) * length);

  // for (i = 0; i < length; i++)
  // {
  //   scanf("%d %d", &ids[i], &keys[i]);
  // }
  length = 12;
  int ids[12] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
  int keys[12] = {14, 27, 17, 16, 13, 10, 1, 5, 12, 8, 12, 0};

  for (i = 0; i < length; i++)
    MaxPqInsert(pq, ids[i], keys[i]);

  MaxPqIncreaseKey(pq, 11, 30);
  MaxPqIncreaseKey(pq, 4, 28);

  for (i = 0; i < length; i++) {
    pq_element *el = MaxPqExtractMax(pq);
    printf("id:%d key:%d\n", el->id, el->key);
  }

  DestroyMaxPq(pq);
}
#include "max-priority-queue.h"
#include <stdio.h>
#include <stdlib.h>

int Parent(int i) { return i >> 1; }
int Left(int i) { return (i << 1) + 1; }
int Right(int i) { return (i << 1) + 2; }

priority_queue *AllocateMaxPq(int size) {
  priority_queue *pq = (priority_queue *)malloc(sizeof(priority_queue));
  pq->heap = (int *)malloc(sizeof(int) * size);
  pq->position_of_id = (int *)malloc(sizeof(int) * size);
  pq->id_at_position = (int *)malloc(sizeof(int) * size);
  pq->size = size;
  pq->heap_size = 0;
  return pq;
}

void DestroyMaxPq(priority_queue *pq) {
  free(pq->heap);
  free(pq->position_of_id);
  free(pq->id_at_position);
  free(pq);
}

void SwapKeys(priority_queue *pq, int i, int j) {
  int *heap = pq->heap;
  int *id_at_position = pq->id_at_position;
  int *position_of_id = pq->position_of_id;

  int i_pos_id = id_at_position[i];
  int j_pos_id = id_at_position[j];

  position_of_id[i_pos_id] = j;
  position_of_id[j_pos_id] = i;

  id_at_position[i] = j_pos_id;
  id_at_position[j] = i_pos_id;

  int temp = heap[i];
  heap[i] = heap[j];
  heap[j] = temp;
}

void MaxPqHeapify(priority_queue *pq, int i) {
  int l, r, largest;
  int *a = pq->heap;

  l = Left(i);
  r = Right(i);
  largest = i;

  if (l >= pq->heap_size)
    return;
  if (l < pq->heap_size && a[i] < a[l])
    largest = l;
  if (r < pq->heap_size && a[largest] < a[r])
    largest = r;

  if (largest == i)
    return;

  SwapKeys(pq, i, largest);
  MaxPqHeapify(pq, largest);
}

void MaxPqSiftUp(priority_queue *pq, int i) {
  int *a = pq->heap;
  while (a[Parent(i)] < a[i]) {
    SwapKeys(pq, i, Parent(i));
    i = Parent(i);
  }
}

void MaxPqIncreaseKey(priority_queue *pq, int id, int new_key) {
  int element_position = pq->position_of_id[id];
  pq->heap[element_position] = new_key;
  MaxPqSiftUp(pq, element_position);
  MaxPqHeapify(pq, element_position);
}

priority_queue_element *MaxPqInsert(priority_queue *pq, int id, int key) {
  priority_queue_element *element =
      (priority_queue_element *)malloc(sizeof(priority_queue_element));
  element->id = id;
  element->key = key;
  pq->position_of_id[id] = pq->heap_size;
  pq->id_at_position[pq->heap_size] = id;
  pq->heap[pq->heap_size] = key;
  pq->heap_size++;

  MaxPqSiftUp(pq, pq->heap_size - 1);
  return element;
}

priority_queue_element *MaxPqExtractMax(priority_queue *pq) {
  priority_queue_element *element =
      (priority_queue_element *)malloc(sizeof(priority_queue_element));
  element->id = pq->id_at_position[0];
  element->key = pq->heap[0];

  SwapKeys(pq, 0, pq->heap_size - 1);
  pq->heap_size--;
  MaxPqHeapify(pq, 0);

  return element;
}

priority_queue *BuildMaxPq(int *ids, int *keys, int input_size, int pq_size) {
  priority_queue *pq = AllocateMaxPq(pq_size);
  pq->heap_size = input_size;
  pq->size = input_size;

  int i;
  for (i = 0; i < input_size; i++) {
    pq->heap[i] = keys[i];
    pq->position_of_id[ids[i]] = i;
    pq->id_at_position[i] = ids[i];
  }

  i = pq->heap_size / 2;
  while (i >= 0)
    MaxPqHeapify(pq, i), i--;

  return pq;
}

#include "max-priority-queue.h"
#include <stdio.h>
#include <stdlib.h>

int Parent(int i) { return i >> 1; }
int Left(int i) { return (i << 1) + 1; }
int Right(int i) { return (i << 1) + 2; }

max_priority_queue *AllocateMaxPq(int size) {
  max_priority_queue *pq =
      (max_priority_queue *)malloc(sizeof(max_priority_queue));
  pq->heap = (int *)malloc(sizeof(int) * size);
  pq->id_position = (int *)malloc(sizeof(int) * size);
  pq->position_id = (int *)malloc(sizeof(int) * size);
  pq->size = size;
  pq->heap_size = 0;
  return pq;
}

void DestroyMaxPq(max_priority_queue *pq) {
  free(pq->heap);
  free(pq->id_position);
  free(pq->position_id);
  free(pq);
}

void SwapKeys(max_priority_queue *pq, int i, int j) {
  int *heap = pq->heap;
  int *position_id = pq->position_id;
  int *id_position = pq->id_position;

  int i_pos_id = position_id[i];
  int j_pos_id = position_id[j];

  id_position[i_pos_id] = j;
  id_position[j_pos_id] = i;

  position_id[i] = j_pos_id;
  position_id[j] = i_pos_id;

  int temp = heap[i];
  heap[i] = heap[j];
  heap[j] = temp;
}

void MaxPqHeapify(max_priority_queue *pq, int i) {
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

void MaxPqSiftUp(max_priority_queue *pq, int i) {
  int *a = pq->heap;
  while (a[Parent(i)] < a[i]) {
    SwapKeys(pq, i, Parent(i));
    i = Parent(i);
  }
}

void MaxPqIncreaseKey(max_priority_queue *pq, int id, int new_key) {
  int element_position = pq->id_position[id];
  pq->heap[element_position] = new_key;
  MaxPqSiftUp(pq, element_position);
}

pq_element *MaxPqInsert(max_priority_queue *pq, int id, int key) {
  pq_element *element = (pq_element *)malloc(sizeof(pq_element));
  element->id = id;
  element->key = key;
  pq->id_position[id] = pq->heap_size;
  pq->position_id[pq->heap_size] = id;
  pq->heap[pq->heap_size] = key;
  pq->heap_size++;

  MaxPqSiftUp(pq, pq->heap_size - 1);
  return element;
}

pq_element *MaxPqExtractMax(max_priority_queue *pq) {
  pq_element *element = (pq_element *)malloc(sizeof(pq_element));
  element->id = pq->position_id[0];
  element->key = pq->heap[0];

  SwapKeys(pq, 0, pq->heap_size - 1);
  pq->heap_size--;
  MaxPqHeapify(pq, 0);

  return element;
}

max_priority_queue *BuildMaxPq(int *ids, int *keys, int input_size,
                               int pq_size) {
  max_priority_queue *pq = AllocateMaxPq(pq_size);
  int i;
  for (i = 0; i < input_size; i++) {
    pq->heap[i] = keys[i];
    pq->id_position[keys[i]] = i;
    pq->position_id[i] = ids[i];
  }
  return pq;
}

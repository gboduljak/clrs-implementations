#include "max-heap.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Parent(int i) { return i >> 1; }
int Left(int i) { return (i << 1) + 1; }
int Right(int i) { return (i << 1) + 2; }

void Swap(int *A, int i, int j) {
  int temp;
  temp = A[i];
  A[i] = A[j];
  A[j] = temp;
}

int Max(heap *heap) { return heap->a[0]; }
int ExtractMax(heap *heap) {
  int max = Max(heap);

  Swap(heap->a, 0, heap->heap_size - 1);
  heap->heap_size--;
  MaxHeapify(heap, 0);
  return max;
}

heap *AllocateMaxHeap(int size) {
  heap *heap = malloc(sizeof heap);
  heap->a = malloc(size * sizeof(int));
  heap->heap_size = 0;
  heap->size = size;
  return heap;
}

void DestroyMaxHeap(heap *heap) {
  free(heap->a);
  free(heap);
}

void MaxHeapify(heap *heap, int i) {
  int l, r, largest;
  int *a = heap->a;

  l = Left(i);
  r = Right(i);
  largest = i;

  if (l >= heap->heap_size)
    return;
  if (l < heap->heap_size && a[i] < a[l])
    largest = l;
  if (r < heap->heap_size && a[largest] < a[r])
    largest = r;

  if (largest == i)
    return;

  Swap(a, i, largest);
  MaxHeapify(heap, largest);
}

void BuildMaxHeap(heap *heap) {
  int i;
  i = heap->heap_size / 2;
  while (i >= 0)
    MaxHeapify(heap, i), i--;
}

void IncreaseKey(heap *heap, int i) {
  int *a = heap->a;
  while (a[Parent(i)] < a[i]) {
    Swap(a, i, Parent(i));
    i = Parent(i);
  }
}

void MaxHeapInsert(heap *heap, int key) {
  heap->a[heap->heap_size] = key;
  IncreaseKey(heap, heap->heap_size);
  heap->heap_size++;
}

void HeapSort(int *A, int size) {
  heap *heap = malloc(sizeof heap);
  heap->a = A;
  heap->heap_size = size;
  heap->size = size;

  int i;

  BuildMaxHeap(heap);

  for (i = heap->heap_size - 1; i >= 0; i--)
    A[i] = ExtractMax(heap);

  free(heap);
}
#include "max-heap.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  int length;
  scanf("%d", &length);
  int i;
  heap *heap = AllocateMaxHeap(100);
  heap->heap_size = length;
  int *A = malloc(sizeof(int) * length);
  for (i = 0; i < length; i++) {
    scanf("%d", &heap->a[i]);
    A[i] = heap->a[i];
  }

  BuildMaxHeap(heap);
  MaxHeapInsert(heap, 100);
  DestroyMaxHeap(heap);

  for (i = 0; i < length; i++) {
    printf("%d ", A[i]);
  }
  printf("\n");

  HeapSort(A, length);

  for (i = 0; i < length; i++)
    printf("%d ", A[i]);
}
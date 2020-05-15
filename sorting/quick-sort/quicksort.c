#include "quicksort.h"

int Partition(int *A, int p, int r) {
  int x = A[r];
  int i = p - 1;
  int j;

  for (j = p; j < r; j++)
    if (A[j] <= x)
      Swap(A, ++i, j);

  Swap(A, ++i, r);
  return i;
}

void QuickSort(int *A, int p, int r) {
  if (p >= r)
    return;

  int q = Partition(A, p, r);
  QuickSort(A, p, q - 1);
  QuickSort(A, q + 1, r);
}
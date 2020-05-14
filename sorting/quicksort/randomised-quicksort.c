#include "randomised-quicksort.h"
#include "quicksort.h"
#include <stdlib.h>
#include <time.h>

void Swap(int *A, int i, int j) {
  int temp = A[i];
  A[i] = A[j];
  A[j] = temp;
}

int RandomisedPartition(int *A, int p, int r) {
  int q = (rand() % (r - p + 1)) + p;
  Swap(A, q, r);
  return Partition(A, p, r);
}

void RandomisedQuicksort(int *A, int p, int r) {
  if (p >= r)
    return;

  int q = RandomisedPartition(A, p, r);
  RandomisedQuicksort(A, p, q - 1);
  RandomisedQuicksort(A, q + 1, r);
}
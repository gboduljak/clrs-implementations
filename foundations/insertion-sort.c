#include "insertion-sort.h"

void InsertionSort(int *A, int length) {
  int i, j, key;
  for (j = 1; j < length; j++) {
    key = A[j];
    i = j - 1;
    while (i > -1 && A[i] > key) {
      A[i + 1] = A[i];
      i = i - 1;
    }
    A[i + 1] = key;
  }
}
#include "counting-sort.h"
#include <stdlib.h>
#include <string.h>

void CountingSort(int *A, int length) {
  int *B = (int *)malloc(sizeof(int) * length);
  int *C = (int *)malloc(sizeof(int) * length);
  int j;

  memset(C, 0, length);

  for (j = 0; j < length; j++)
    C[A[j]]++;
  for (j = 1; j < length; j++)
    C[j] = C[j - 1] + C[j];
  for (j = 0; j < length; j++)
    C[j]--;

  for (j = length - 1; j >= 0; j--)
    B[C[A[j]]] = A[j], C[A[j]]--;

  for (j = 0; j< length; j++)
    A[j] = B[j];

  free(C);
  free(B);
}
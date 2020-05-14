#include "quicksort.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  int length;
  int i;
  scanf("%d", &length);
  int *A = malloc(sizeof(int) * length);
  for (i = 0; i < length; i++)
    scanf("%d", &A[i]);

  QuickSort(A, 0, length - 1);

  for (i = 0; i < length; i++)
    printf("%d ", A[i]);
  free(A);
}
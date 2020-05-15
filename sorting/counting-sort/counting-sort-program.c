#include "counting-sort.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  int length;
  scanf("%d", &length);
  int i;
  int *A = malloc(sizeof(int) * length);
  for (i = 0; i < length; i++)
    scanf("%d", &A[i]);

  int *B = CountingSort(A, length);

  for (i = 0; i < length; i++)
    printf("%d ", B[i]);
  free(A);
  free(B);
}
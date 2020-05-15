#include "radix-sort.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
  int length, digits;
  scanf("%d %d", &length, &digits);

  int i;
  int *A = malloc(sizeof(int) * length);
  for (i = 0; i < length; i++)
    scanf("%d", &A[i]);

  RadixSort(A, digits, length);

  for (i = 0; i < length; i++)
    printf("%d ", A[i]);

  free(A);
}
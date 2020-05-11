#include "maximum-subarray.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  int length;
  scanf("%d", &length);
  int i;
  int *P = malloc(sizeof(int) * length);
  int *A = malloc(sizeof(int) * (length - 1));

  for (i = 0; i < length; i++)
    scanf("%d", &P[i]);

  for (i = 1; i < length; i++)
    A[i] = P[i] - P[i - 1];

  subarray_info result = FindMaximumSubarray(A, 0, length - 2);

  printf("Price changes are \n");
  for (i = 0; i < length - 1; i++)
    printf("%d ", A[i]);
  printf("\n");
  printf("Maximum subarray: low=%d hi=%d sum=%d\n", result.low, result.high,
         result.sum);
  printf("Max profit is %d \n", result.sum);
  free(A);
}
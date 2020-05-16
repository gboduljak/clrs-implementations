#include "bucket-sort.h"
#include "bucket.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  int length;
  scanf("%d", &length);
  int i;
  double *A = malloc(sizeof(double) * length);
  for (i = 0; i < length; i++)
    scanf("%lf", &A[i]);

  BucketSort(A, length);
  for (i = 0; i < length; i++)
    printf("%lf ", A[i]);

  free(A);
}
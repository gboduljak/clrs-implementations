#include "randomised-select.h"
#include "randomised-quicksort.h"

int RandomisedSelect(int *A, int p, int r, int i) {
  if (p == r)
    return A[p];
  int q = RandomisedPartition(A, p, r);
  int k = q - p + 1;
  if (i == k)
    return A[q];
  if (i < k)
    return RandomisedSelect(A, p, q - 1, i);
  return RandomisedSelect(A, q + 1, r, i - k);
}
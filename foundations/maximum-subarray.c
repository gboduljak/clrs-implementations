#include <stdio.h>
#include <stdlib.h>

#include "maximum-subarray.h"

#define infinity 1 << 16

int max(int a, int b) { return a < b ? b : a; }

subarray_info FindMaximumSubarray(int *A, int low, int high) {
  subarray_info result;

  if (low == high) {
    result.low = low;
    result.high = high;
    result.sum = A[low];
    return result;
  }

  int mid = (low + high) / 2;

  subarray_info left = FindMaximumSubarray(A, low, mid);
  subarray_info right = FindMaximumSubarray(A, mid + 1, high);
  subarray_info crossing = FindMaximumCrossingSubarray(A, low, mid, high);

  if (left.sum > max(right.sum, crossing.sum))
    return left;
  if (right.sum > max(left.sum, crossing.sum))
    return right;

  return crossing;
}

subarray_info FindMaximumCrossingSubarray(int *A, int low, int mid, int high) {
  subarray_info result;

  int sum;
  int left_sum = -(infinity), max_left_ix;
  int right_sum = -(infinity), max_right_ix;
  max_left_ix = 0, max_right_ix = 0;
  int i;

  sum = 0;
  i = mid;
  while (i >= low) {
    sum += A[i];
    if (sum > left_sum) {
      left_sum = sum;
      max_left_ix = i;
    }
    i--;
  }

  sum = 0;
  i = mid + 1;
  while (i <= high) {
    sum += A[i];
    if (sum > right_sum) {
      right_sum = sum;
      max_right_ix = i;
    }
    i++;
  }

  result.low = max_left_ix;
  result.high = max_right_ix;
  result.sum = left_sum + right_sum;

  return result;
}

subarray_info FindMaximumSubarrayBruteforce(int *A, int low, int high) {
  subarray_info result;
  result.sum = -(infinity);
  int i, j, sum;
  int *P = malloc(sizeof(int) * (high - low + 1));

  P[0] = A[0];

  for (i = 1; i <= high; i++)
    P[i] = P[i - 1] + A[i];

  for (i = 0; i <= high; i++) {
    for (j = i + 1; j <= high; j++) {
      sum = i >= 1 ? P[j] - P[i - 1] : P[j];
      if (sum > result.sum) {
        result.sum = sum;
        result.low = i;
        result.high = j;
      }
    }
  }

  free(P);
  return result;
}
#include <stdio.h>
#include <stdlib.h>

typedef struct subarray_info {
  int low;
  int high;
  int sum;
} subarray_info;

subarray_info FindMaximumSubarrayBruteforce(int *A, int low, int high);
subarray_info FindMaximumSubarray(int *A, int low, int high);
subarray_info FindMaximumCrossingSubarray(int *A, int low, int mid, int high);
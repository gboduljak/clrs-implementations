#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "maximum-subarray.h"

int main()
{
  int length;
  scanf("%d", &length);
  int i;
  int *P = malloc(sizeof(int) * length);
  int *A = malloc(sizeof(int) * (length - 1));

  for (i = 0; i < length; i++)
    scanf("%d", &P[i]);

  int cross_over = 0;

  for (i = 1; i < length; i++)
  {
    struct timespec start_bf, end_bf, start_d_c, end_d_c;
    clock_gettime(CLOCK_MONOTONIC_RAW, &start_bf);
    subarray_info result_bruteforce = FindMaximumSubarrayBruteforce(A, 0, i);
    clock_gettime(CLOCK_MONOTONIC_RAW, &end_bf);

    clock_gettime(CLOCK_MONOTONIC_RAW, &start_d_c);
    subarray_info result_d_c = FindMaximumSubarray(A, 0, i);
    clock_gettime(CLOCK_MONOTONIC_RAW, &end_d_c);

    long elapsed_bf = 1000000 * (end_bf.tv_nsec - start_bf.tv_nsec);
    long elapsed_d_c = 1000000 * (end_d_c.tv_nsec - start_d_c.tv_nsec);

    printf("Divide and Conquer: %ld ms, Bruteforce: %ld ms \n", elapsed_d_c, elapsed_bf);

    if (elapsed_d_c <= elapsed_bf && !cross_over)
    {
      printf("Divide and Conquer implementation becomes faster when n=%d\n", i + 1);
      cross_over = 1;
      break;
    }
  }

  free(A);
}
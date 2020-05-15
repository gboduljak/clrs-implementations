#include "counting-sort.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>

int Digit(int num, int d)
{
  int power = pow(10, d);
  int prev_power = pow(10, d - 1);
  return (num - (num / power) * power) / prev_power;
}

void CountingSortOnDigit(int *A, int d, int length)
{
  int *B = (int *)malloc(sizeof(int) * length);
  int *C = (int *)malloc(sizeof(int) * (10));
  int i, j;

  for (j = 0; j < 10; j++)
    C[j] = 0;
  for (j = 0; j < length; j++)
    C[Digit(A[j], d)]++;
  for (j = 1; j < 10; j++)
    C[j] = C[j - 1] + C[j];
  for (j = 0; j < 10; j++)
    C[j]--;

  for (j = length - 1; j >= 0; j--)
  {
    B[C[Digit(A[j], d)]] = A[j];
    C[Digit(A[j], d)]--;
  }

  for (i = 0; i < length; i++)
    A[i] = B[i];

  free(C);
  free(B);
}
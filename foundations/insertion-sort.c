#include <stdio.h>
#include <stdlib.h>

void InsertionSort(int *A, int length) {
  int i, j, key;
  for (j = 1; j < length; j++) {
    key = A[j];
    i = j - 1;
    while (i > -1 && A[i] > key) {
      A[i + 1] = A[i];
      i = i - 1;
    }
    A[i + 1] = key;
  }
}

int main() {
  int length;
  scanf("%d", &length);
  int i;
  int *A = malloc(sizeof(int) * length);
  for (i = 0; i < length; i++)
    scanf("%d", &A[i]);
  InsertionSort(A, length);
  for (i = 0; i < length; i++)
    printf("%d ", A[i]);
  free(A);
}
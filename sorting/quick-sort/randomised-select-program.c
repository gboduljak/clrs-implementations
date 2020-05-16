#include "randomised-select.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL));

  int length;
  int i;
  scanf("%d", &length);
  int *A = malloc(sizeof(int) * length);
  for (i = 0; i < length; i++)
    scanf("%d", &A[i]);
  for (i = 1; i <= length; i++)
    printf("%d-th smallest element is: %d\n", i,
           RandomisedSelect(A, 0, length - 1, i));
  free(A);
}
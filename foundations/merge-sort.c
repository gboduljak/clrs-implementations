#include <stdio.h>
#include <stdlib.h>

#define infinity 1 << 30

void Merge(int *A, int p, int q, int r)
{
  int n1 = q - p + 1;
  int n2 = r - q;

  int *L = malloc(sizeof(int) * (n1 + 1));
  int *R = malloc(sizeof(int) * (n2 + 1));

  int i, j, k;

  for (i = 0; i < n1; i++)
    L[i] = A[p + i];
  L[i] = infinity;
  for (j = 0; j < n2; j++)
    R[j] = A[q + j + 1];
  R[j] = infinity;

  i = 0;
  j = 0;

  for (k = p; k <= r; k++)
  {
    if (L[i] <= R[j])
    {
      A[k] = L[i];
      i++;
    }
    else
    {
      A[k] = R[j];
      j++;
    }
  }

  free(L);
  free(R);
}

void MergeSort(int *A, int lo, int hi)
{
  if (lo == hi)
    return;
  int mid = (lo + hi) / 2;
  MergeSort(A, lo, mid);
  MergeSort(A, mid + 1, hi);
  Merge(A, lo, mid, hi);
}

int main()
{
  int length;
  scanf("%d", &length);
  int i;
  int *A = malloc(sizeof(int) * length);
  for (i = 0; i < length; i++)
    scanf("%d", &A[i]);
  MergeSort(A, 0, length - 1);
  for (i = 0; i < length; i++)
    printf("%d ", A[i]);
  free(A);
}
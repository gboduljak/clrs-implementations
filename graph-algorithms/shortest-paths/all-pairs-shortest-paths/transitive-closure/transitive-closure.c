#include "transitive-closure.h"
#include "stdio.h"
#include "stdlib.h"

int **AllocateMatrix(int n) {
  int **m = malloc(sizeof(int *) * n);
  int i;
  for (i = 0; i < n; i++)
    m[i] = (int *)malloc(sizeof(int) * n);
  return m;
}

transitive_closure_result TransitiveClosure(graph *g) {
  transitive_closure_result result;
  int **t = AllocateMatrix(g->V + 1);
  int i, j, k, n;
  t = g->weight;
  n = g->V;

  for (i = 1; i < n; i++)
    for (j = 1; j < n; j++)
      t[i][j] = i == j || g->weight[i][j];

  for (k = 1; k < n; k++)
    for (i = 1; i < n; i++)
      for (j = 1; j < n; j++)
        t[i][j] = t[i][j] || (t[i][k] && t[k][j]);

  result.t = t;
  return result;
}
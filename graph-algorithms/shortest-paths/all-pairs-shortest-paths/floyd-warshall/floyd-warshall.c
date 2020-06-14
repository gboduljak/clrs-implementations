#include "floyd-warshall.h"
#include "stdio.h"
#include "stdlib.h"

int **AllocateMatrix(int n) {
  int **m = malloc(sizeof(int *) * n);
  int i;
  for (i = 0; i < n; i++)
    m[i] = (int *)malloc(sizeof(int) * n);
  return m;
}

floyd_warshall_result FloydWarshall(graph *g) {
  floyd_warshall_result result;
  int **d = AllocateMatrix(g->V + 1);
  int **p = AllocateMatrix(g->V + 1);
  int i, j, k, n;
  n = g->V;
  d = g->weight;

  for (i = 1; i < n; i++)
    for (j = 1; j < n; j++)
      p[i][j] = (d[i][j] == infinity || i == j) ? NIL_VERTEX : i;

  for (k = 1; k < n; k++) {
    int **d_k = AllocateMatrix(g->V + 1);
    int **p_k = AllocateMatrix(g->V + 1);

    for (i = 1; i < n; i++)
      for (j = 1; j < n; j++)
        if (d[i][k] + d[k][j] < d[i][j])
          d_k[i][j] = d[i][k] + d[k][j], p_k[i][j] = p[k][j];
        else
          d_k[i][j] = d[i][j], p_k[i][j] = p[i][j];

    d = d_k;
    p = p_k;
  }

  result.d = d;
  result.p = p;
  return result;
}

void PrintFloydWarshall(floyd_warshall_result result, int i, int j) {
  if (i == j) {
    printf("%d", i);
    return;
  } else if (result.p[i][j] == NIL_VERTEX)
    return;
  else {
    PrintFloydWarshall(result, i, result.p[i][j]);
    printf(" -> %d", j);
  }
}
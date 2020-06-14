#include "dynamic-programming-on-edges.h"
#include "../../relax.h"
#include "stdio.h"
#include "stdlib.h"

int Min(int a, int b) { return a <= b ? a : b; }

shortest_paths ExtendAllShortestPaths(graph *g, int **l, int **p, int **w) {
  int **l_next = (int **)malloc(sizeof(int *) * (g->V + 1));
  int **p_next = (int **)malloc(sizeof(int *) * (g->V + 1));
  int i, j, k;

  for (i = 0; i < g->V; i++) {
    l_next[i] = (int *)malloc(sizeof(int *) * (g->V + 1));
    p_next[i] = (int *)malloc(sizeof(int *) * (g->V + 1));
    for (j = 0; j < g->V; j++)
      l_next[i][j] = l[i][j], p_next[i][j] = p[i][j];
  }

  for (k = 0; k < g->V; k++)
    for (i = 0; i < g->V; i++)
      for (j = 0; j < g->V; j++)
        if (l[i][k] + w[k][j] < l_next[i][j])
          l_next[i][j] = l[i][k] + w[k][j], p_next[i][j] = k;

  shortest_paths result;
  result.d = l_next;
  result.p = p_next;
  return result;
}

shortest_paths SlowAllPairsShortestPaths(graph *g) {
  shortest_paths result;

  int **l = (int **)malloc(sizeof(int *) * (g->V + 1));
  int **p = (int **)malloc(sizeof(int *) * (g->V + 1));

  int m, n, u, v;
  n = g->V;
  l = g->weight;

  for (u = 0; u < g->V; u++)
    p[u] = (int *)malloc(sizeof(int) * (g->V + 1));

  for (u = 0; u < g->V; u++)
    for (v = 0; v < g->V; v++)
      p[u][v] = l[u][v] < infinity ? u : NIL_VERTEX;

  result.d = l;
  result.p = p;

  for (m = 2; m <= n - 1; m++)
    result = ExtendAllShortestPaths(g, result.d, result.p, g->weight);

  return result;
}

void PrintSlowAllPairsShortestPaths(shortest_paths result, int i, int j) {
  if (i == j) {
    printf("%d", i);
    return;
  } else if (result.p[i][j] == NIL_VERTEX)
    return;
  else {
    PrintSlowAllPairsShortestPaths(result, i, result.p[i][j]);
    printf(" -> %d", j);
  }
}

shortest_paths FasterAllPairsShortestPaths(graph *g) {
  shortest_paths result;
  int **l = (int **)malloc(sizeof(int *) * (g->V + 1));
  int m = 1;
  l = g->weight;
  m = 1;

  while (m < g->V - 1) {
    l = ExtendAllShortestPaths(g, l, l, l).d;
    m = m * 2;
  }

  result.d = l;
  return result;
}
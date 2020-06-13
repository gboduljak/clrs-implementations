#include "dynamic-programming-on-edges.h"
#include "../../relax.h"
#include "stdio.h"
#include "stdlib.h"

int Min(int a, int b) { return a <= b ? a : b; }

int **ExtendAllShortestPaths(graph *g, int **l, int **w) {
  int **l_next = (int **)malloc(sizeof(int *) * (g->V + 1));
  int i, j, k;

  for (i = 0; i < g->V; i++) {
    l_next[i] = (int *)malloc(sizeof(int *) * (g->V + 1));
    for (j = 0; j < g->V; j++)
      l_next[i][j] = l[i][j];
  }

  for (k = 0; k < g->V; k++)
    for (i = 0; i < g->V; i++)
      for (j = 0; j < g->V; j++)
        l_next[i][j] = Min(l_next[i][j], (l[i][k] + w[k][j]));

  return l_next;
}

shortest_paths SlowAllPairsShortestPaths(graph *g) {
  shortest_paths result;
  int **l = (int **)malloc(sizeof(int *) * (g->V + 1));
  int m, n;
  n = g->V;
  l = g->weight;

  for (m = 2; m <= n - 1; m++)
    l = ExtendAllShortestPaths(g, l, g->weight);

  result.d = l;
  return result;
}

shortest_paths FasterAllPairsShortestPaths(graph *g) {
  shortest_paths result;
  int **l = (int **)malloc(sizeof(int *) * (g->V + 1));
  int m = 1;
  l = g->weight;
  m = 1;

  while (m < g->V - 1) {
    l = ExtendAllShortestPaths(g, l, l);
    m = m * 2;
  }

  result.d = l;
  return result;
}
#include "bellman-ford.h"
#include "../../relax.h"
#include "stdio.h"

bellman_ford_result BellmanFord(graph *g, int s) {
  bellman_ford_result result;
  result.has_negative_weight_cycle = 0;
  int i, j;
  single_source_structs structs = InitializeSingleSource(g, s);
  int *d = structs.d;

  for (i = 0; i < g->V; i++)
    for (j = 0; j < g->E; j++)
      Relax(structs, g->edges + j);

  for (j = 0; j < g->E && result.has_negative_weight_cycle; j++) {
    int d_before_relax = d[(g->edges[j]).v];
    Relax(structs, g->edges + j);
    int d_after_relax = d[(g->edges[j]).v];
    if (d_after_relax < d_before_relax)
      result.has_negative_weight_cycle = 1;
  }
  result.p = structs.p;
  result.d = structs.d;
  return result;
}

void PrintBellmanFordPath(bellman_ford_result result, int s, int v) {
  if (v == NIL_VERTEX)
    return;

  PrintBellmanFordPath(result, s, result.p[v]);

  if (result.p[v] != NIL_VERTEX)
    printf(" -> %d", v);
  else
    printf("%d", v);
}
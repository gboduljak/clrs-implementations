#include "kruskal.h"
#include "stdio.h"
#include "stdlib.h"

int OrderEdgesByWeightIncreasing(const void *x, const void *y) {
  const edge *lhs = x;
  const edge *rhs = y;
  return lhs->weight < rhs->weight ? -1 : (lhs->weight > rhs->weight);
}

kruskal_result MstKruskal(graph *g) {
  int weight = 0, edge_ix, a_ix = 0;
  edge e;
  edge *A = malloc(sizeof(edge) * (g->V - 1));
  dsu *dsu = AllocateDsu(g->V + 1);

  qsort(g->edges, g->E, sizeof(edge), OrderEdgesByWeightIncreasing);

  for (edge_ix = 0; edge_ix < g->E; edge_ix++) {
    e = g->edges[edge_ix];
    if (FindSet(dsu->nodes + e.u) != FindSet(dsu->nodes + e.v)) {
      Union(dsu->nodes + e.u, dsu->nodes + e.v);
      weight += e.weight;
      A[a_ix].u = e.u;
      A[a_ix].v = e.v;
      A[a_ix].weight = e.weight;
      A[a_ix].id = e.id;
      a_ix++;
    }
  }

  kruskal_result result;
  result.tree = A;
  result.weight = weight;
  return result;
}

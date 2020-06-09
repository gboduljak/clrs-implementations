#include "relax.h"

void Relax(single_source_structs structs, edge *e) {
  int *d = structs.d;
  int *p = structs.p;
  int u = e->u;
  int v = e->v;
  int w = e->weight;

  if (d[u] + w < d[v])
    d[v] = d[u] + w, p[v] = u;
}
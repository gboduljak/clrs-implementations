#include "initialize-single-source.h"
#include "stdlib.h"

single_source_structs InitializeSingleSource(graph *g, int s) {
  single_source_structs structs;
  int u;
  structs.p = (int *)malloc(sizeof(int) * (g->V + 1));
  structs.d = (int *)malloc(sizeof(int) * (g->V + 1));
  for (u = 0; u < g->V; u++)
    structs.p[u] = NIL_VERTEX, structs.d[u] = infinity;
  structs.d[s] = 0;
  return structs;
}

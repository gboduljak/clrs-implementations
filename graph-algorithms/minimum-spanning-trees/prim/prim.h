#include "../../../data-structures/heaps/min-priority-queue.h"
#include "../../graph.h"

typedef struct prim_result {
  edge *tree;
  int *p;
  int r;
  int weight;
} prim_result;

prim_result MstPrim(graph *g, int r);
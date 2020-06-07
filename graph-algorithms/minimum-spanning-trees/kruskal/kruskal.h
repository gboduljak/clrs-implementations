#include "../../../data-structures/disjoint-set-union/dsu.h"
#include "../../../data-structures/linked-list/linked-list.h"
#include "../../graph.h"

typedef struct kruskal_result {
  edge *tree;
  int *p;
  int r;
  int weight;
} kruskal_result;

kruskal_result MstKruskal(graph *g);
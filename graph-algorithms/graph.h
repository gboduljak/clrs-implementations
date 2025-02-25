#include "../data-structures/linked-list/linked-list.h"

#ifndef GRAPH_H
#define GRAPH_H

#define white 0
#define gray 1
#define black 2

#define NIL_VERTEX -1
#define infinity (1 << 28)

typedef struct edge {
  int u;
  int v;
  int weight;
  int id;
} edge;

typedef struct graph {
  linked_list **Adj;
  int V;
  int E;
  edge *edges;
  int **weight;
} graph;

#endif
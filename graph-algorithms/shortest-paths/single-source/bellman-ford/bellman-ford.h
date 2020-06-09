#include "../../initialize-single-source.h"

typedef struct bellman_ford_result {
  int *p;
  int *d;
  int has_negative_weight_cycle;
} bellman_ford_result;

bellman_ford_result BellmanFord(graph *g, int s);
void PrintBellmanFordPath(bellman_ford_result result, int s, int v);
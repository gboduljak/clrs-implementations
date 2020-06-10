#include "../../initialize-single-source.h"

typedef struct dag_shortest_path_result {
  int *p;
  int *d;
} dag_shortest_path_result;

dag_shortest_path_result DagShortestPath(graph *g, int s);
void PrintDagShortestPath(dag_shortest_path_result result, int s, int v);
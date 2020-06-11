#include "../../initialize-single-source.h"

typedef struct dijkstra_result {
  int *p;
  int *d;
} dijkstra_result;

dijkstra_result Dijkstra(graph *g, int s);
void PrintDijkstraPath(dijkstra_result result, int s, int v);
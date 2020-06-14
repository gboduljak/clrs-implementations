#include "../../initialize-single-source.h"

typedef struct shortest_paths {
  int **d;
  int **p;
} shortest_paths;

shortest_paths SlowAllPairsShortestPaths(graph *g);
shortest_paths FasterAllPairsShortestPaths(graph *g);
void PrintSlowAllPairsShortestPaths(shortest_paths result, int i, int j);
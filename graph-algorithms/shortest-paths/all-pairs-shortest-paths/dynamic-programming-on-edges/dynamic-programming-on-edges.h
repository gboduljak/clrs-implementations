#include "../../initialize-single-source.h"

typedef struct shortest_paths {
  int **d;
  int **p;
} shortest_paths;

shortest_paths SlowAllPairsShortestPaths(graph *g);
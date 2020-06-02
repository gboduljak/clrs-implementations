#include "../../graph.h"

typedef struct bfs_result {
  int *p;
  int *d;
} bfs_result;

bfs_result Bfs(graph *g, int s);
void PrintBfsPath(bfs_result result, int s, int v);
#include "../../graph.h"

typedef struct dfs_result {
  int *p;
  int *f;
  int *d;
} dfs_result;

dfs_result Dfs(graph *g, int s);
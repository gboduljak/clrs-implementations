#include "../../graph.h"

#define tree_edge 0
#define back_edge 1
#define forward_edge 2
#define cross_edge 3

typedef struct dfs_result {
  int *p;
  int *f;
  int *d;
  int **e;
} dfs_result;

dfs_result Dfs(graph *g, int s);
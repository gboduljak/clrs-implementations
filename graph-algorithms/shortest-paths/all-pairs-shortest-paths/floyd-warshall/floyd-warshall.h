#include "../../initialize-single-source.h"

typedef struct floyd_warshall_result {
  int **d;
  int **p;
} floyd_warshall_result;

floyd_warshall_result FloydWarshall(graph *g);
void PrintFloydWarshall(floyd_warshall_result result, int i, int j);
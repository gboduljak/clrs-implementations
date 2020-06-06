#include "../../../../data-structures/linked-list/linked-list.h"
#include "../../../graph.h"

typedef struct kosaraju_result {
  int *scc;
  linked_list **sccs;
  int sccs_count;
} kosaraju_result;

kosaraju_result Kosaraju(graph *g);
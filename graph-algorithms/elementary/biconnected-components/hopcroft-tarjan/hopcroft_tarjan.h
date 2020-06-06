#include "../../../../data-structures/linked-list/linked-list.h"
#include "../../../../data-structures/linked-list/stack.h"

#include "../../../graph.h"

typedef struct hopcroft_tarjan_result {
  edge **bccs;
  edge *bridges;
  linked_list *articulation_points;
  int bridges_count;
  int articulation_point_count;
} hopcroft_tarjan_result;

hopcroft_tarjan_result HopcroftTarjan(graph *g);
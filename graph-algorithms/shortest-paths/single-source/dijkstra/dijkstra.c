#include "dijkstra.h"
#include "../../../../data-structures/heaps/min-priority-queue.h"
#include "../../relax.h"

#include "stdio.h"

dijkstra_result Dijkstra(graph *g, int s) {
  dijkstra_result result;
  single_source_structs structs = InitializeSingleSource(g, s);
  int u, v;
  edge e;
  priority_queue *q = AllocateMinPq(g->V + 1);

  for (u = 0; u < g->V; u++)
    MinPqInsert(q, u, infinity);

  MinPqDecreaseKey(q, s, 0);

  while (q->heap_size) {
    priority_queue_element *u_element = MinPqExtractMin(q);
    u = u_element->id;
    linked_list_node *v_node = g->Adj[u]->nil->next;

    while (v_node != g->Adj[u]->nil) {
      v = v_node->key;
      e.u = u;
      e.v = v;
      e.weight = g->weight[u][v];
      Relax(structs, &e);
      v_node = v_node->next;
    }
  }

  result.p = structs.p;
  result.d = structs.d;
  return result;
}

void PrintDijkstraPath(dijkstra_result result, int s, int v) {
  if (v == NIL_VERTEX)
    return;

  PrintDijkstraPath(result, s, result.p[v]);

  if (result.p[v] != NIL_VERTEX)
    printf(" -> %d", v);
  else
    printf("%d", v);
}
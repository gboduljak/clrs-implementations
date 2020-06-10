#include "dag-shortest-path.h"
#include "../../../elementary/topological-sort/dfs/topological-sort.h"
#include "../../relax.h"
#include "stdio.h"

dag_shortest_path_result DagShortestPath(graph *g, int s) {
  dag_shortest_path_result result;
  single_source_structs structs = InitializeSingleSource(g, s);
  result.d = structs.d;
  result.p = structs.p;
  linked_list *topological_order = TopSort(g);
  linked_list_node *source = topological_order->nil->next;
  int u, v;
  linked_list_node *v_node;
  edge e;
  while (source != topological_order->nil && source->key != s)
    source = source->next;

  while (source != topological_order->nil) {
    u = source->key;
    v_node = g->Adj[u]->nil->next;

    while (v_node != g->Adj[u]->nil) {
      v = v_node->key;
      e.u = u;
      e.v = v;
      e.weight = g->weight[u][v];
      Relax(structs, &e);
      v_node = v_node->next;
    }
    source = source->next;
  }
  return result;
}

void PrintDagShortestPath(dag_shortest_path_result result, int s, int v) {
  if (v == NIL_VERTEX)
    return;

  PrintDagShortestPath(result, s, result.p[v]);

  if (result.p[v] != NIL_VERTEX)
    printf(" -> %d", v);
  else
    printf("%d", v);
}
#include "prim.h"
#include "stdio.h"
#include "stdlib.h"

prim_result MstPrim(graph *g, int r) {
  int u, v, u_weight, v_weight, weight = 0;
  int edge_ix = 0;
  int *p = malloc(sizeof(int) * g->V);
  int *enqueued = malloc(sizeof(int) * g->V);

  edge *tree = malloc(sizeof(edge) * (g->V - 1));
  priority_queue *q = AllocateMinPq(g->V);

  for (u = 0; u < g->V; u++)
    p[u] = NIL_VERTEX, MinPqInsert(q, u, infinity), enqueued[u] = 1;

  MinPqDecreaseKey(q, r, 0);
  while (q->heap_size) {
    priority_queue_element *u_element = MinPqExtractMin(q);
    enqueued[u] = 0;
    u = u_element->id;
    u_weight = u_element->key;
    weight += u_weight;

    if (u != r) {
      tree[edge_ix].u = p[u];
      tree[edge_ix].v = u;
      edge_ix++;
    }

    linked_list_node *v_node = g->Adj[u]->nil->next;

    while (v_node != g->Adj[u]->nil) {
      v = v_node->key;
      v_weight = MinPqLookupKey(q, v);

      if (enqueued[v] && g->weight[u][v] < v_weight)
        MinPqDecreaseKey(q, v, g->weight[u][v]), p[v] = u;
      v_node = v_node->next;
    }
  }

  free(enqueued);
  DestroyMinPq(q);

  prim_result result;
  result.weight = weight;
  result.p = p;
  result.r = r;
  result.tree = tree;
  return result;
}

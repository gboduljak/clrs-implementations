#include "hierholzer.h"
#include "stdio.h"
#include "stdlib.h"

int cycle_completed = 0;
typedef struct hierholzer_structures {
  int *out_degree;
  linked_list *vertices_to_consider;
  linked_list_node *vertices_to_consider_lookup;
} hierholzer_structures;

void HierholzerDfs(graph *g, hierholzer_structures structs, queue *cycle, int w,
                   int u) {
  if (cycle_completed)
    return;

  int *out_degree = structs.out_degree;
  linked_list_node *v_node;
  int v;

  Enqueue(cycle, u);

  v_node = g->Adj[u]->nil->next;
  while (v_node != g->Adj[u]->nil && !cycle_completed) {
    v = v_node->key;

    ListDelete(g->Adj[u], v_node);
    out_degree[u]--;
    if (v == w)
      cycle_completed = 1, Enqueue(cycle, w);
    else
      HierholzerDfs(g, structs, cycle, w, v);

    v_node = v_node->next;
  }
}

// assumes an Euler tour exists <-> in-degree(v) = out-degree(v) for every v in
// g.V
linked_list *Hierholzer(graph *g, int s) {
  linked_list_node *v_node;
  linked_list *built_tour = AllocateLinkedList();
  int *out_degree = (int *)malloc(sizeof(int) * (g->V + 1));
  queue *cycle;
  int u, v;

  hierholzer_structures structs;
  structs.out_degree = out_degree;

  for (u = 0; u < g->V; u++) {
    out_degree[u] = 0;
    v_node = g->Adj[u]->nil->next;
    while (v_node != g->Adj[u]->nil) {
      out_degree[u]++;
      v = v_node->key;
      v_node = v_node->next;
    }
  }

  if (!g->V)
    return built_tour = NULL;

  linked_list_node *extension_vertex;

  cycle = AllocateQueue();
  cycle_completed = 0;
  HierholzerDfs(g, structs, cycle, s, s);

  while (!QueueEmpty(cycle)) {
    u = cycle->q->nil->prev->key;
    if (out_degree[u])
      extension_vertex = ListInsertBack(built_tour, Dequeue(cycle));
    else
      ListInsertBack(built_tour, Dequeue(cycle));
  }

  while (extension_vertex != NULL) {
    cycle = AllocateQueue();
    cycle_completed = 0;

    HierholzerDfs(g, structs, cycle, extension_vertex->key,
                  extension_vertex->key);

    linked_list *extension_cycle = AllocateLinkedList();
    linked_list_node *splice_vertex = extension_vertex;

    extension_vertex = NULL;
    while (!QueueEmpty(cycle)) {
      u = cycle->q->nil->prev->key;
      if (out_degree[u])
        extension_vertex = ListInsertBack(extension_cycle, Dequeue(cycle));
      else
        ListInsertBack(extension_cycle, Dequeue(cycle));
    }
    ListReplace(built_tour, splice_vertex, extension_cycle);
  }

  linked_list_node *current = built_tour->nil->next;
  linked_list *euler_tour = AllocateLinkedList();

  while (current != built_tour->nil)
    ListInsertBack(euler_tour, current->key), current = current->next;

  return euler_tour;
}
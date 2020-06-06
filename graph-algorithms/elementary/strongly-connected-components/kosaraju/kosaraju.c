#include "kosaraju.h"
#include "../../topological-sort/dfs/topological-sort.h"
#include "stdio.h"
#include "stdlib.h"

graph *TransposeGraph(graph *g) {
  int u, v;
  linked_list_node *v_node;
  graph *g_t = malloc(sizeof(graph));
  g_t->V = g->V;
  g_t->E = g->E;
  g_t->Adj = (linked_list **)malloc(sizeof(linked_list *) * (g->V));

  for (u = 0; u < g->V; u++)
    g_t->Adj[u] = AllocateLinkedList();

  for (u = 0; u < g->V; u++) {
    v_node = g->Adj[u]->nil->next;
    while (v_node != g->Adj[u]->nil) {
      v = v_node->key;
      ListInsert(g_t->Adj[v], u);
      v_node = v_node->next;
    }
  }
  return g_t;
}

void SccDfs(graph *g, linked_list *scc, int *scc_label, int scc_index, int *c,
            int u) {
  int v;
  linked_list_node *v_node;

  c[u] = gray;
  v_node = g->Adj[u]->nil->next;

  while (v_node != g->Adj[u]->nil) {
    v = v_node->key;
    if (c[v] == white)
      SccDfs(g, scc, scc_label, scc_index, c, v);
    v_node = v_node->next;
  }

  scc_label[u] = scc_index;
  ListInsert(scc, u);
}

kosaraju_result Kosaraju(graph *g) {
  kosaraju_result result;
  int u;
  int *c = (int *)malloc(sizeof(int) * (g->V));
  int *scc_label = (int *)malloc(sizeof(int) * (g->V));
  linked_list **sccs = (linked_list **)malloc(sizeof(linked_list) * (g->V));

  int sccs_count = 0;
  int scc_index = -1;

  for (u = 0; u < g->V; u++)
    c[u] = white, scc_label[u] = -1;

  graph *g_t = TransposeGraph(g);
  linked_list *ordering = TopSort(g);
  linked_list_node *ordering_node = ordering->nil->next;

  while (ordering_node != ordering->nil) {
    u = ordering_node->key;
    if (c[u] == white) {
      sccs_count++;
      scc_index++;
      linked_list *scc = AllocateLinkedList();
      SccDfs(g_t, scc, scc_label, scc_index, c, u);
      sccs[scc_index] = scc;
    }
    ordering_node = ordering_node->next;
  }

  result.scc = scc_label;
  result.sccs = sccs;
  result.sccs_count = sccs_count;
  return result;
}
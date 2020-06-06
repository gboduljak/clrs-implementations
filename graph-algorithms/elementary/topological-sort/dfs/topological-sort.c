#include "topological-sort.h"
#include "stdio.h"
#include "stdlib.h"

int time;

void TopSortDfsVisit(graph *g, int *c, linked_list *order, int u) {
  linked_list_node *v_node;
  int v;

  time++;
  c[u] = gray;

  v_node = g->Adj[u]->nil->next;
  while (v_node != g->Adj[u]->nil) {
    v = v_node->key;
    if (c[v] == white)
      TopSortDfsVisit(g, c, order, v);
    v_node = v_node->next;
  }

  time++;
  c[u] = black;
  ListInsert(order, u);
}

linked_list *TopSort(graph *g) {
  int u;
  int *c = (int *)malloc(sizeof(int) * (g->V));
  linked_list *order = AllocateLinkedList();

  for (u = 0; u < g->V; u++)
    c[u] = white;

  time = 0;

  for (u = 0; u < g->V; u++)
    if (c[u] == white)
      TopSortDfsVisit(g, c, order, u);

  return order;
}
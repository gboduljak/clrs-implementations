#include "kahn.h"
#include "stdio.h"
#include "stdlib.h"

linked_list *Kahn(graph *g) {
  int u, v;
  int *in_degree = (int *)malloc(sizeof(int) * (g->V));
  queue *order = AllocateQueue();
  queue *q = AllocateQueue();

  for (u = 0; u < g->V; u++)
    in_degree[u] = 0;

  for (u = 0; u < g->V; u++) {
    linked_list_node *adj_list_node = g->Adj[u]->nil->next;
    while (adj_list_node != g->Adj[u]->nil)
      in_degree[adj_list_node->key]++, adj_list_node = adj_list_node->next;
  }

  for (u = 0; u < g->V; u++)
    if (!in_degree[u])
      Enqueue(q, u);

  while (!QueueEmpty(q)) {
    v = Dequeue(q);
    linked_list_node *adj_list_node = g->Adj[v]->nil->next;
    while (adj_list_node != g->Adj[v]->nil) {
      u = adj_list_node->key;
      in_degree[u]--;
      if (!in_degree[u])
        Enqueue(q, u);
      adj_list_node = adj_list_node->next;
    }

    Enqueue(order, v);
  }

  return order->q;
}

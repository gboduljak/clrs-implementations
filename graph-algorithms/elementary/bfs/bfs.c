#include "bfs.h"
#include "../../../data-structures/linked-list/queue.h"
#include "stdio.h"
#include "stdlib.h"

bfs_result Bfs(graph *g, int s) {
  int u, v;
  linked_list_node *v_node;
  int *p = (int *)malloc(sizeof(int) * (g->V));
  int *d = (int *)malloc(sizeof(int) * (g->V));
  int *c = (int *)malloc(sizeof(int) * (g->V));
  queue *Q = AllocateQueue();

  for (u = 0; u < g->V; u++)
    c[u] = white, d[u] = infinity, p[u] = NIL_VERTEX;

  c[s] = gray;
  d[s] = 0;

  Enqueue(Q, s);

  while (!QueueEmpty(Q)) {
    u = Dequeue(Q);
    v_node = g->Adj[u]->nil->next;
    while (v_node != g->Adj[u]->nil) {
      v = v_node->key;
      if (c[v] == white) {
        c[v] = gray;
        d[v] = d[u] + 1;
        p[v] = u;
        Enqueue(Q, v);
      }
      v_node = v_node->next;
    }
    c[u] = black;
  }
  free(c);
  bfs_result result;
  result.p = p;
  result.d = d;
  return result;
}

void PrintBfsPath(bfs_result result, int s, int v) {
  if (v == NIL_VERTEX)
    return;

  PrintBfsPath(result, s, result.p[v]);

  if (result.p[v] != NIL_VERTEX)
    printf(" -> %d", v);
  else
    printf("%d", v);
}
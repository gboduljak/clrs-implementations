#include "dfs.h"
#include "stdio.h"
#include "stdlib.h"

int time;

void DfsVisit(graph *g, int *c, int *d, int *f, int *p, int u) {
  linked_list_node *v_node;
  int v;

  time++;
  d[u] = time;
  c[u] = gray;

  v_node = g->Adj[u]->nil->next;
  while (v_node != g->Adj[u]->nil) {
    v = v_node->key;
    if (c[v] == white)
      p[v] = u, DfsVisit(g, c, d, f, p, v);
    v_node = v_node->next;
  }

  time++;
  c[u] = black;
  f[u] = time;
}

dfs_result Dfs(graph *g, int s) {
  int u;
  int *p = (int *)malloc(sizeof(int) * (g->V));
  int *d = (int *)malloc(sizeof(int) * (g->V));
  int *f = (int *)malloc(sizeof(int) * (g->V));
  int *c = (int *)malloc(sizeof(int) * (g->V));

  for (u = 0; u < g->V; u++)
    c[u] = white, d[u] = -1, f[u] = infinity, p[u] = NIL_VERTEX;

  time = 0;

  for (u = 0; u < g->V; u++)
    if (c[u] == white)
      DfsVisit(g, c, d, f, p, u);

  dfs_result result;

  result.d = d;
  result.f = f;
  result.p = p;
  return result;
}
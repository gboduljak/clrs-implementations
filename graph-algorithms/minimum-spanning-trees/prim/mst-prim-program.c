#include "prim.h"
#include "stdio.h"
#include "stdlib.h"

int vertices_n, edges_n, r;

int main() {
  int i, u, v, w, e;
  scanf("%d %d %d", &vertices_n, &edges_n, &r);

  graph g;
  g.V = vertices_n;
  g.E = 2 * edges_n;
  g.Adj = (linked_list **)malloc(sizeof(linked_list *) * (vertices_n + 1));
  g.weight = (int **)malloc(sizeof(int *) * g.V);

  for (i = 0; i < vertices_n; i++)
    g.Adj[i] = AllocateLinkedList(),
    g.weight[i] = (int *)malloc(sizeof(int) * g.V);

  for (i = 0; i < edges_n; i++) {
    scanf("%d %d %d", &u, &v, &w);
    ListInsert(g.Adj[u], v);
    ListInsert(g.Adj[v], u);
    g.weight[u][v] = w;
    g.weight[v][u] = w;
  }

  prim_result result = MstPrim(&g, r);

  printf("minimum spanning tree from %d has weight %d\n", r, result.weight);
  printf("minimum spanning tree has edges: { ");

  for (e = 0; e < g.V - 1; e++) {
    if (e != g.V - 2)
      printf("(%d, %d), ", result.tree[e].u, result.tree[e].v);
    else
      printf("(%d, %d)", result.tree[e].u, result.tree[e].v);
  }

  printf(" }\n");
  return 0;
}
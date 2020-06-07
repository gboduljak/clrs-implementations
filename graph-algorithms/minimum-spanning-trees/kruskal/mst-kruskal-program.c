#include "kruskal.h"
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
  g.edges = (edge *)malloc(sizeof(edge) * g.E);

  for (i = 0; i < vertices_n; i++)
    g.Adj[i] = AllocateLinkedList(),
    g.weight[i] = (int *)malloc(sizeof(int) * g.V);
  e = 0;

  for (i = 0; i < edges_n; i++) {
    scanf("%d %d %d", &u, &v, &w);
    ListInsert(g.Adj[u], v);
    ListInsert(g.Adj[v], u);
    g.weight[u][v] = w;
    g.weight[v][u] = w;
    g.edges[e].u = u;
    g.edges[e].v = v;
    g.edges[e].weight = w;
    g.edges[e].id = e;
    e++;
    g.edges[e].v = u;
    g.edges[e].u = v;
    g.edges[e].weight = w;
    g.edges[e].id = e;
  }

  kruskal_result result = MstKruskal(&g);

  printf("minimum spanning tree has weight %d\n", result.weight);
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
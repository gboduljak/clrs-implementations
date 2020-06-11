#include "../../../../data-structures/heaps/priority-queue.h"
#include "../../../../data-structures/linked-list/linked-list.h"
#include "dijkstra.h"
#include "stdio.h"
#include "stdlib.h"

int vertices_n, edges_n, s;

int main() {
  int i, u, v, w;
  scanf("%d %d %d", &vertices_n, &edges_n, &s);

  graph g;
  g.V = vertices_n;
  g.E = edges_n;
  g.Adj = (linked_list **)malloc(sizeof(linked_list *) * (vertices_n + 1));
  g.edges = (edge *)malloc(sizeof(edge) * edges_n);
  g.weight = (int **)malloc(sizeof(int *) * (vertices_n + 1));

  for (i = 0; i < vertices_n; i++)
    g.Adj[i] = AllocateLinkedList(),
    g.weight[i] = (int *)malloc(sizeof(int) * (vertices_n + 1));

  for (i = 0; i < edges_n; i++) {
    scanf("%d %d %d", &u, &v, &w);
    ListInsert(g.Adj[u], v);
    g.edges[i].u = u;
    g.edges[i].v = v;
    g.edges[i].id = i;
    g.edges[i].weight = w;
    g.weight[u][v] = w;
  }

  dijkstra_result result = Dijkstra(&g, s);

  for (u = 0; u < vertices_n; u++) {
    if (u == s)
      continue;
    printf("shortest path cost from %d to %d is %d\n", s, u, result.d[u]);
    printf("shortest path from %d to %d is: ", s, u);
    PrintDijkstraPath(result, s, u);
    printf("\n");
  }
  return 0;
}
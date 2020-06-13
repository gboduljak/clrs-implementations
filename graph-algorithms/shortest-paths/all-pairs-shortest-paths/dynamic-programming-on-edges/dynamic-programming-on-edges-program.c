#include "../../../../data-structures/linked-list/linked-list.h"
#include "dynamic-programming-on-edges.h"
#include "stdio.h"
#include "stdlib.h"
int vertices_n, edges_n;

int main() {
  int i, j, u, v, w;
  scanf("%d %d", &vertices_n, &edges_n);

  graph g;
  g.V = vertices_n;
  g.E = edges_n;
  g.Adj = (linked_list **)malloc(sizeof(linked_list *) * (vertices_n + 1));
  g.edges = (edge *)malloc(sizeof(edge) * edges_n);
  g.weight = (int **)malloc(sizeof(int *) * (vertices_n + 1));

  for (i = 0; i < vertices_n; i++) {
    g.Adj[i] = AllocateLinkedList();
    g.weight[i] = (int *)malloc(sizeof(int) * (vertices_n + 1));

    for (j = 0; j < vertices_n; j++)
      g.weight[i][j] = i != j ? infinity : 0;
  }

  for (i = 0; i < edges_n; i++) {
    scanf("%d %d %d", &u, &v, &w);
    ListInsert(g.Adj[u], v);
    g.edges[i].u = u;
    g.edges[i].v = v;
    g.edges[i].id = i;
    g.edges[i].weight = w;
    g.weight[u][v] = w;
  }

  shortest_paths slow_result = SlowAllPairsShortestPaths(&g);
  shortest_paths fast_result = FasterAllPairsShortestPaths(&g);

  printf("slow shortest paths matrix: \n");
  for (u = 1; u < vertices_n; u++) {
    for (v = 1; v < vertices_n; v++)
      printf("%d ", slow_result.d[u][v]);
    printf("\n");
  }
  for (u = 1; u < vertices_n; u++)
    for (v = 1; v < vertices_n; v++)
      printf("slow shortest path cost from %d to %d is %d\n", u, v,
             slow_result.d[u][v]);

  printf("\n");
  printf("faster shortest paths matrix: \n");
  for (u = 1; u < vertices_n; u++) {
    for (v = 1; v < vertices_n; v++)
      printf("%d ", fast_result.d[u][v]);
    printf("\n");
  }
  for (u = 1; u < vertices_n; u++)
    for (v = 1; v < vertices_n; v++)
      printf("faster shortest path cost from %d to %d is %d\n", u, v,
             fast_result.d[u][v]);

  return 0;
}
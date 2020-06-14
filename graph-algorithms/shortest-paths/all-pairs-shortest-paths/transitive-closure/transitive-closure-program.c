#include "../../../../data-structures/linked-list/linked-list.h"
#include "stdio.h"
#include "stdlib.h"
#include "transitive-closure.h"
int vertices_n, edges_n;

int main() {
  int i, j, u, v;
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
      g.weight[i][j] = 0;
  }

  for (i = 0; i < edges_n; i++) {
    scanf("%d %d", &u, &v);
    ListInsert(g.Adj[u], v);
    g.edges[i].u = u;
    g.edges[i].v = v;
    g.edges[i].id = i;
    g.edges[i].weight = 1;
    g.weight[u][v] = 1;
  }

  transitive_closure_result result = TransitiveClosure(&g);

  printf("transitive closure matrix: \n");
  for (u = 1; u < vertices_n; u++) {
    for (v = 1; v < vertices_n; v++)
      printf("%d ", result.t[u][v]);
    printf("\n");
  }

  for (i = 1; i < vertices_n; i++)
    for (j = 1; j < vertices_n; j++)
      if (result.t[i][j])
        printf("there exists a path from %d to %d\n", i, j);
      else
        printf("there is no path from %d to %d\n", i, j);

  return 0;
}
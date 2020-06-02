#include "stdio.h"
#include "stdlib.h"

#include "bfs.h"

int vertices_n, edges_n, s;

int main() {
  int i, u, v;
  scanf("%d %d %d", &vertices_n, &edges_n, &s);

  graph g;
  g.V = vertices_n;
  g.E = edges_n;
  g.Adj = (linked_list **)malloc(sizeof(linked_list *) * (vertices_n + 1));

  for (i = 0; i < vertices_n; i++)
    g.Adj[i] = AllocateLinkedList();

  for (i = 0; i < edges_n; i++) {
    scanf("%d %d", &u, &v);
    ListInsert(g.Adj[u], v);
  }

  bfs_result result = Bfs(&g, s);

  for (u = 0; u < vertices_n; u++) {
    if (u == s)
      continue;
    printf("distance from %d to %d is %d edges\n", s, u, result.d[u]);
    printf("shortest path from %d to %d is: ", s, u);
    PrintBfsPath(result, s, u);
    printf("\n");
  }
  return 0;
}
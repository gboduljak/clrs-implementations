#include "stdio.h"
#include "stdlib.h"

#include "dfs.h"

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

  dfs_result result = Dfs(&g, s);

  for (u = 0; u < vertices_n; u++) {
    if (u == s)
      continue;
    printf("starting time of %d is %d\n", u, result.d[u]);
    printf("finishing time of  %d is %d\n", s, result.f[u]);
    printf("\n");
  }

  const char *edge_classes[4] = {"tree", "back", "forward", "cross"};

  for (u = 0; u < vertices_n; u++) {
    linked_list_node *v_node = g.Adj[u]->nil->next;
    while (v_node != g.Adj[u]->nil) {
      v = v_node->key;
      printf("edge (%d,%d) is a %s edge.\n", u, v,
             edge_classes[result.e[u][v]]);
      v_node = v_node->next;
    }
  }
  return 0;
}
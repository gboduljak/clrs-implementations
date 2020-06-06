#include "kosaraju.h"
#include "stdio.h"
#include "stdlib.h"

int vertices_n, edges_n;

int main() {
  int i, u, v;
  scanf("%d %d", &vertices_n, &edges_n);

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

  kosaraju_result result = Kosaraju(&g);

  printf("there are %d strongly connected components.\n", result.sccs_count);
  printf("those are: \n");

  for (i = 0; i < result.sccs_count; i++) {
    linked_list *scc = result.sccs[i];
    linked_list_node *scc_node = scc->nil->next;

    printf("scc #%d: ", i + 1);

    while (scc_node != scc->nil) {
      u = scc_node->key;
      printf("%d ", u);
      scc_node = scc_node->next;
    }
    printf("\n");
  }

  return 0;
}
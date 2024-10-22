#include "stdio.h"
#include "stdlib.h"

#include "hierholzer.h"

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

  linked_list *tour = Hierholzer(&g, s);
  linked_list_node *node = tour->nil->next;
  printf("an Euler tour has length: %d \n", tour->length);
  printf("an Euler tour is: ");

  while (node != tour->nil)
    printf("%d ", node->key), node = node->next;

  printf("\n");
  return 0;
}
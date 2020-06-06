#include "stdio.h"
#include "stdlib.h"

#include "topological-sort.h"

int vertices_n, edges_n;

int main() {
  int i, u, v;
  scanf("%d %d", &vertices_n, &edges_n);

  graph g;
  g.V = vertices_n;
  g.E = edges_n;
  g.Adj = (linked_list **)malloc(sizeof(linked_list *) * (vertices_n + 1));
  char **vertices_names = (char **)malloc(sizeof(char *) * (vertices_n + 1));

  for (i = 0; i < vertices_n; i++)
    g.Adj[i] = AllocateLinkedList();

  for (i = 0; i < edges_n; i++) {
    scanf("%d %d", &u, &v);
    ListInsert(g.Adj[u], v);
  }

  for (i = 0; i < vertices_n; i++) {
    int name_length;
    scanf("%d", &name_length);
    char *vertex_name = malloc(sizeof(char) * (name_length + 1));
    scanf("%s", vertex_name);
    vertices_names[i] = vertex_name;
  }

  linked_list *ordering = TopSort(&g);
  linked_list_node *node = ordering->nil->next;

  while (node != ordering->nil) {
    char *vertex_name = vertices_names[node->key];
    if (node->next != ordering->nil)
      printf("%s -> ", vertex_name);
    else
      printf("%s\n", vertex_name);
    node = node->next;
  }

  return 0;
}
#include "stdio.h"
#include "stdlib.h"

#include "hopcroft_tarjan.h"

int vertices_n, edges_n;

int main() {
  int i, u, v;
  scanf("%d %d", &vertices_n, &edges_n);

  graph g;
  g.V = vertices_n;
  g.E = 2 * edges_n;
  g.Adj = (linked_list **)malloc(sizeof(linked_list *) * (vertices_n + 1));

  for (i = 0; i < vertices_n; i++)
    g.Adj[i] = AllocateLinkedList();

  for (i = 0; i < edges_n; i++) {
    scanf("%d %d", &u, &v);
    ListInsert(g.Adj[u], v);
    ListInsert(g.Adj[v], u);
  }

  hopcroft_tarjan_result hc_result = HopcroftTarjan(&g);
  printf("there are %d articulation points in this graph.\n",
         hc_result.articulation_point_count);
  printf("those are : ");

  linked_list_node *ap_node = hc_result.articulation_points->nil->next;
  edge bridge;

  while (ap_node != hc_result.articulation_points->nil)
    printf("%d ", ap_node->key), ap_node = ap_node->next;
  printf("\n");

  printf("there are %d bridges in this graph.\n", hc_result.bridges_count);
  printf("those are : ");
  for (i = 0; i < hc_result.bridges_count; i++)
    bridge = hc_result.bridges[i], printf("(%d, %d) ", bridge.u, bridge.v);
  printf("\n");

  return 0;
}
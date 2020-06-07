#include "hopcroft_tarjan.h"
#include "stdio.h"
#include "stdlib.h"

int time;

typedef struct hc_structures {
  int *p;
  int *color;
  int *d;
  int *f;
  int *low;
  int **edges_table;
  stack *edges_stack;

} hc_structures;

int Min(int a, int b) { return a <= b ? a : b; }

void HcDfsVisit(graph *g, hopcroft_tarjan_result *result,
                hc_structures hc_structures, int u) {
  int v;
  linked_list_node *v_node;
  int *color = hc_structures.color;
  int *p = hc_structures.p;
  int *d = hc_structures.d;
  int *f = hc_structures.f;
  int *low = hc_structures.low;
  int **edges_table = hc_structures.edges_table;
  stack *edges_stack = hc_structures.edges_stack;

  linked_list *articulation_points = result->articulation_points;
  edge *bridges = result->bridges;
  int bridges_count = result->bridges_count;
  int children_count = 0;
  int added_to_articulation_points = 0;

  time++;
  d[u] = time;
  low[u] = d[u];
  color[u] = gray;

  v_node = g->Adj[u]->nil->next;
  while (v_node != g->Adj[u]->nil) {
    v = v_node->key;

    if (color[v] == white) {
      p[v] = u;
      children_count++;

      HcDfsVisit(g, result, hc_structures, v);

      low[u] = Min(low[u], low[v]);

      if ((p[u] != NIL_VERTEX && low[v] >= d[u]) ||
          (p[u] == NIL_VERTEX &&
           children_count >= 2)) // u is an articulation point
      {
        if (!added_to_articulation_points) {
          result->articulation_point_count++;
          ListInsert(articulation_points, u);
          added_to_articulation_points = 1;
        }
      }
      if (low[v] > d[u]) // (u, v) is a bridge
      {
        bridges[bridges_count].u = u;
        bridges[bridges_count].v = v;
        bridges[bridges_count].id = edges_table[u][v];
        bridges_count++;
        result->bridges_count = bridges_count;
      }
    } else if (v != p[u] && low[u] > d[v]) // color[v] = gray
      low[u] = Min(low[u], d[v]);          // back edge to v
    v_node = v_node->next;
  }
  time++;
  f[u] = time;
  color[u] = black;
}

hopcroft_tarjan_result HopcroftTarjan(graph *g) {
  hopcroft_tarjan_result result;
  hc_structures hc_structures;
  int u, v, e = -1;
  int *color = (int *)malloc(sizeof(int) * (g->V));
  int *p = (int *)malloc(sizeof(int) * (g->V));
  int *d = (int *)malloc(sizeof(int) * (g->V));
  int *f = (int *)malloc(sizeof(int) * (g->V));
  int *low = (int *)malloc(sizeof(int) * (g->V));
  int **edges_table = (int **)malloc(sizeof(int *) * (g->V));
  stack *edges_stack = AllocateStack();

  hc_structures.color = color;
  hc_structures.p = p;
  hc_structures.d = d;
  hc_structures.f = f;
  hc_structures.low = low;
  hc_structures.edges_table = edges_table;
  hc_structures.edges_stack = edges_stack;

  result.articulation_points = AllocateLinkedList();
  result.bridges = malloc(sizeof(edge) * sizeof(g->E));
  result.articulation_point_count = 0;
  result.bridges_count = 0;
  g->edges = malloc(sizeof(edge) * sizeof(g->E));

  for (u = 0; u < g->V; u++) {
    color[u] = white;
    p[u] = NIL_VERTEX;
    edges_table[u] = (int *)malloc(sizeof(int) * (g->V));

    linked_list_node *v_node = g->Adj[u]->nil->next;
    while (v_node != g->Adj[u]->nil) {
      v = v_node->key;
      ++e;
      g->edges[e].u = u;
      g->edges[e].v = v;
      g->edges[e].id = e;
      edges_table[u][v] = e;
      v_node = v_node->next;
    }
  }

  time = 0;

  for (u = 0; u < g->V; u++)
    if (color[u] == white)
      HcDfsVisit(g, &result, hc_structures, u);

  return result;
}
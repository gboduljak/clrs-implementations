#include "../../../data-structures/linked-list/linked-list.h"
#include <stdio.h>
#include <stdlib.h>

int infinity = -1000000;

int V, E, from, target;
int **weight;
int *dp;
int *n;
linked_list **graph;

int max(int a, int b) { return a <= b ? b : a; }

int longest_path_from(int u) {
  if (u == target)
    return 0;
  if (dp[u] != infinity)
    return dp[u];

  linked_list *children = graph[u];
  linked_list_node *child = children->nil->next;

  int w;
  while (child != children->nil) {
    w = child->key;
    if (weight[u][w] + longest_path_from(w) > dp[u]) {
      dp[u] = weight[u][w] + longest_path_from(w);
      n[u] = w;
    }
    child = child->next;
  }

  return dp[u];
}

void print_longest_path(int u) {
  if (u == target) {
    printf("%d", target);
    return;
  }
  printf("%d -> ", u);
  print_longest_path(n[u]);
}

int main() {
  scanf("%d %d %d %d", &V, &E, &from, &target);
  int i, j, u, v, w;
  graph = malloc(sizeof(linked_list *) * (V + 1));
  weight = (int **)malloc(sizeof(int *) * (V + 1));
  dp = (int *)malloc(sizeof(int) * (V + 1));
  n = (int *)malloc(sizeof(int) * (V + 1));

  for (i = 0; i <= V; i++) {
    graph[i] = AllocateLinkedList();
    weight[i] = (int *)malloc(sizeof(int) * (V + 1));
    dp[i] = infinity;
  }
  for (i = 0; i <= E; i++) {
    scanf("%d %d %d", &u, &v, &w);
    weight[u][v] = w;
    ListInsert(graph[u], v);
  }

  int path = longest_path_from(from);
  printf("longest path %d -> %d cost is: %d\n", from, target, path);
  printf("longest path %d -> %d is: ", from, target);
  print_longest_path(from);
  printf("\n");

  for (i = 0; i <= V; i++) {
    DellocateLinkedList(graph[i]);
    free(weight[i]);
  }
  free(dp);
  free(n);
  free(graph);
  free(weight);
  return 0;
}
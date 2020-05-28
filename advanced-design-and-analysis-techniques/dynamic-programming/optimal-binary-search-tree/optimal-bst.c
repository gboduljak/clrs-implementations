#include "optimal-bst.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

optimal_bst_result OptimalBst(double *p, double *q, int n) {
  optimal_bst_result result;

  double **e = (double **)malloc(sizeof(double *) * (n + 2));
  double **w = (double **)malloc(sizeof(double *) * (n + 2));
  int **root = (int **)malloc(sizeof(int *) * (n + 2));
  int i, j, l, r;
  double t;

  for (i = 0; i <= (n + 1); i++) {
    e[i] = malloc(sizeof(double) * (n + 1));
    w[i] = malloc(sizeof(double) * (n + 1));
    root[i] = malloc(sizeof(int) * (n + 1));
  }

  for (i = 1; i <= (n + 1); i++)
    e[i][i - 1] = q[i - 1], w[i][i - 1] = q[i - 1]; // base cases

  for (l = 1; l <= n; l++) {
    for (i = 1; i <= n - l + 1; i++) {
      j = i + l - 1;
      e[i][j] = 1 << 28;
      w[i][j] = w[i][j - 1] + p[j] + q[j];

      for (r = i; r <= j; r++) {
        t = e[i][r - 1] + e[r + 1][j] + w[i][j];

        if (t < e[i][j])
          e[i][j] = t, root[i][j] = r;
      }
    }
  }

  result.e = e;
  result.w = w;
  result.root = root;
  result.expected_cost = e[1][n];
  return result;
}

char *concat(const char *s1, const char *s2) {
  char *result =
      malloc(strlen(s1) + strlen(s2) + 1); // +1 for the null-terminator
  strcpy(result, s1);
  strcat(result, s2);
  return result;
}

// inspired by
// https://stackoverflow.com/questions/36802354/print-binary-tree-in-a-pretty-way-using-c
void PrettyPrint(const char *prefix, int **root, int i, int j, int is_left) {
  if (i > j)
    return;

  printf("%s", prefix);
  printf("%s", is_left ? "├──" : "└──");
  int root_key = root[i][j];
  printf("%d\n", root_key);
  if (i == j)
    return;

  char *next_level_prefix = concat(prefix, is_left ? "│   " : "    ");

  PrettyPrint(next_level_prefix, root, i, root_key - 1, 1);
  PrettyPrint(next_level_prefix, root, root_key + 1, j, 0);
}

void PrintOptimalBst(optimal_bst_result *result, int n) {
  PrettyPrint("", result->root, 1, n, 0);
}

void DeallocateOptimalBstTables(optimal_bst_result *result, int n) {
  int i;
  for (i = 0; i <= (n + 1); i++) {
    free(result->e[i]);
    free(result->w[i]);
    free(result->root[i]);
  }
  free(result->e);
  free(result->w);
  free(result->root);
}
#include "simplified-edit-distance.h"
#include "stdio.h"
#include "stdlib.h"

int MinEditOpsAux(int **dp, int **op, char *x, char *y, int i, int j, int m,
                  int n) {
  if (i == m)
    return n - j;
  if (j == n)
    return m - i;
  if (dp[i][j] != -1)
    return dp[i][j];

  if (x[i] == y[j]) {
    dp[i][j] = MinEditOpsAux(dp, op, x, y, i + 1, j + 1, m, n);
    op[i][j] = nothing;
    return dp[i][j];
  }
  // replace x[i] with y[j]
  int ops_if_replace = 1 + MinEditOpsAux(dp, op, x, y, i + 1, j + 1, m, n);
  // insert y[j] before x[i]
  int ops_if_insert = 1 + MinEditOpsAux(dp, op, x, y, i, j + 1, m, n);
  // delete x[i]
  int ops_if_delete = 1 + MinEditOpsAux(dp, op, x, y, i + 1, j, m, n);

  dp[i][j] = ops_if_replace;
  op[i][j] = replace;
  if (ops_if_insert < dp[i][j]) {
    dp[i][j] = ops_if_insert;
    op[i][j] = insert;
  }
  if (ops_if_delete < dp[i][j]) {
    dp[i][j] = ops_if_delete;
    op[i][j] = delete;
  }
  return dp[i][j];
}

edit_distance_result MinEditOps(char *x, char *y, int m, int n) {
  edit_distance_result result;
  int i, j;
  int **dp = (int **)malloc(sizeof(int *) * (m + 1));
  int **op = (int **)malloc(sizeof(int *) * (m + 1));

  for (i = 0; i <= m; i++)
    dp[i] = (int *)malloc(sizeof(int) * (n + 1)),
    op[i] = (int *)malloc(sizeof(int) * (n + 1));

  for (i = 0; i <= m; i++)
    for (j = 0; j <= n; j++)
      dp[i][j] = -1;

  result.ops_required = MinEditOpsAux(dp, op, x, y, 0, 0, m, n);
  result.dp = dp;
  result.op = op;
  return result;
}

void PrintEditSequence(int **op, char *x, char *y, int i, int j, int m, int n) {
  if (i == m) {
    if (j < n)
      printf("copy word2[%d...%d]", j, n);
    return;
  }
  if (j == n) {
    if (i < m)
      printf("delete word1[%d...%d]", i, m);
    return;
  }
  switch (op[i][j]) {
  case replace:
    printf("replace %c with %c\n", x[i], y[j]);
    PrintEditSequence(op, x, y, i + 1, j + 1, m, n);
    break;
  case insert:
    printf("insert %c\n", y[j]);
    PrintEditSequence(op, x, y, i, j + 1, m, n);
    break;
  case delete:
    printf("delete %c\n", x[i]);
    PrintEditSequence(op, x, y, i + 1, j, m, n);
    break;
  default:
    PrintEditSequence(op, x, y, i + 1, j + 1, m, n);
    break;
  }
}
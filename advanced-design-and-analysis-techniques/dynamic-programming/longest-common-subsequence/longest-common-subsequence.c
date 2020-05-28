#include "longest-common-subsequence.h"
#include "stdio.h"
#include "stdlib.h"

int Max(int a, int b) { return a <= b ? b : a; }

lcs_result LcsLength(char *x, char *y, int m, int n) {
  lcs_result result;
  int i, j;
  int **c = (int **)malloc(sizeof(int *) * (m + 1));
  int **b = (int **)malloc(sizeof(int *) * (m + 1));

  for (i = 0; i <= m; i++)
    c[i] = (int *)malloc(sizeof(int) * (n + 1)),
    b[i] = (int *)malloc(sizeof(int) * (n + 1));

  for (j = 0; j <= n; j++)
    c[0][j] = 0;
  for (i = 0; i <= m; i++)
    c[i][0] = 0;

  for (i = 1; i <= m; i++)
    for (j = 1; j <= n; j++)
      if (x[i] == y[j])
        c[i][j] = 1 + c[i - 1][j - 1], b[i][j] = x_m_1_y_n_1;
      else if (c[i - 1][j] >= c[i][j - 1])
        c[i][j] = c[i - 1][j], b[i][j] = x_m_1_y_n;
      else
        c[i][j] = c[i][j - 1], b[i][j] = x_m_y_n_1;

  result.c = c;
  result.b = b;
  result.length = c[m][n];
  return result;
}

int LcsLengthAux(char *x, char *y, int m, int n, int **b, int **c) {
  if (m == 0 || n == 0)
    return c[m][n] = 0;
  if (c[m][n] != -1)
    return c[m][n];

  if (x[m] == y[n]) {
    c[m][n] = 1 + LcsLengthAux(x, y, m - 1, n - 1, b, c);
    b[m][n] = x_m_1_y_n_1;
  } else if (LcsLengthAux(x, y, m - 1, n, b, c) >=
             LcsLengthAux(x, y, m, n - 1, b, c)) {
    c[m][n] = LcsLengthAux(x, y, m - 1, n, b, c);
    b[m][n] = x_m_1_y_n;
  } else {
    c[m][n] = LcsLengthAux(x, y, m, n - 1, b, c);
    b[m][n] = x_m_y_n_1;
  }

  return c[m][n];
}

lcs_result LcsLengthMemoised(char *x, char *y, int m, int n) {
  lcs_result result;
  int i, j;
  int **c = (int **)malloc(sizeof(int *) * (m + 1));
  int **b = (int **)malloc(sizeof(int *) * (m + 1));

  for (i = 0; i <= m; i++)
    c[i] = (int *)malloc(sizeof(int) * (n + 1)),
    b[i] = (int *)malloc(sizeof(int) * (n + 1));

  for (i = 0; i <= m; i++)
    for (j = 0; j <= n; j++)
      c[i][j] = -1;

  LcsLengthAux(x, y, m, n, b, c);
  result.b = b;
  result.c = c;
  result.length = c[m][n];
  return result;
}

void PrintLcs(int **b, char *x, char *y, int i, int j) {
  if (i == 0 || j == 0)
    return;

  if (b[i][j] == x_m_1_y_n_1)
    PrintLcs(b, x, y, i - 1, j - 1), printf("%c", x[i]);
  else if (b[i][j] == x_m_1_y_n)
    PrintLcs(b, x, y, i - 1, j);
  else
    PrintLcs(b, x, y, i, j - 1);
}
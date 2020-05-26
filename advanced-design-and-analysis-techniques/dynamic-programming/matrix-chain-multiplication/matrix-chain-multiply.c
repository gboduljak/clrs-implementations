#include "matrix-chain-multiply.h"
#include <stdio.h>
#include <stdlib.h>

void PrintMatrix(int **m, int length) {
  int i, j;
  for (i = 1; i < length; i++) {
    for (j = 1; j < length; j++) {
      printf("%d ", m[i][j]);
    }
    printf("\n");
  }
}

matrix_chain_multiply_result MatrixChainOrder(int *p, int length) {
  int n = length, i, j, k, l, q;
  int **m = malloc(sizeof(int *) * (length + 1));
  int **s = malloc(sizeof(int *) * (length + 1));

  for (i = 0; i < (n + 1); i++) {
    m[i] = malloc(sizeof(int) * (length + 1));
    s[i] = malloc(sizeof(int) * (length + 1));
  }

  for (i = 1; i <= n; i++)
    m[i][i] = 0;

  for (l = 2; l <= n; l++) {
    for (i = 1; i <= n - l + 1; i++) {
      j = i + l - 1;
      m[i][j] = 1 << 28;
      for (k = i; k < j; k++) {
        q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
        if (q < m[i][j]) {
          s[i][j] = k;
          m[i][j] = q;
        }
      }
    }
  }

  matrix_chain_multiply_result result;
  result.m = m;
  result.s = s;
  result.min_multiplications = m[1][n - 1];
  return result;
}

void PrintOptimalParens(int **s, int i, int j) {
  if (i == j) {
    printf("A%d", i);
    return;
  }

  printf("(");
  PrintOptimalParens(s, i, s[i][j]);
  PrintOptimalParens(s, s[i][j] + 1, j);
  printf(")");
}
#include "matrix-chain-multiply.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  int p[] = {5, 10, 3, 12, 5, 50, 6};
  matrix_chain_multiply_result result = MatrixChainOrder(p, 7);
  PrintMatrix(result.m, 7);
  PrintMatrix(result.s, 7);
  PrintOptimalParens(result.s, 1, 6);
}
typedef struct matrix_chain_multiply_result {
  int **m;
  int **s;
  int min_multiplications;
} matrix_chain_multiply_result;

void PrintMatrix(int **m, int length);
matrix_chain_multiply_result MatrixChainOrder(int *p, int length);
void PrintOptimalParens(int **s, int i, int j);
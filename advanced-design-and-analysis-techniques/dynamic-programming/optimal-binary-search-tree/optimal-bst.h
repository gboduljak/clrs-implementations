typedef struct optimal_bst_result {
  double **e;
  double **w;
  int **root;
  double expected_cost;
} optimal_bst_result;

optimal_bst_result OptimalBst(double *p, double *q, int n);
void PrintOptimalBst(optimal_bst_result *result, int n);
void DeallocateOptimalBstTables(optimal_bst_result *result, int n);
#include "optimal-bst.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  int n, i;
  scanf("%d", &n);

  double *p = malloc(sizeof(double) * (n + 1));
  double *q = malloc(sizeof(double) * (n + 1));

  for (i = 0; i <= n; i++)
    scanf("%lf", &p[i]);
  for (i = 0; i <= n; i++)
    scanf("%lf", &q[i]);

  optimal_bst_result result = OptimalBst(p, q, n);

  printf("optimal expected cost is %lf\n", result.expected_cost);
  printf("optimal bst looks like :\n");
  PrintOptimalBst(&result, n);
}
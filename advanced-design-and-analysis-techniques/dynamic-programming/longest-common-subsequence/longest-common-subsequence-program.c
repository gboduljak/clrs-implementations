#include "longest-common-subsequence.h"
#include "stdio.h"
#include "stdlib.h"

int main() {
  int m, n;
  scanf("%d %d", &m, &n);
  char *x = malloc(sizeof(char) * (m + 1));
  char *y = malloc(sizeof(char) * (n + 1));
  scanf("%s", x);
  scanf("%s", y);

  lcs_result result = LcsLength(x, y, m - 1, n - 1);
  printf("lcs of (%s, %s) has length %d.\n", x + 1, y + 1, result.length);
  printf("lcs of (%s, %s) is ", x + 1, y + 1);
  PrintLcs(result.b, x, y, m - 1, n - 1);
  free(x);
  free(y);
}
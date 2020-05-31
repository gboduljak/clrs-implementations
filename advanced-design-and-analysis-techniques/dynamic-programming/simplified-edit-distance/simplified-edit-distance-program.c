#include "simplified-edit-distance.h"
#include "stdio.h"
#include "stdlib.h"

int main() {
  int m, n;
  scanf("%d %d", &m, &n);
  char *x = malloc(sizeof(char) * (m + 1));
  char *y = malloc(sizeof(char) * (n + 1));
  scanf("%s", x);
  scanf("%s", y);

  edit_distance_result result = MinEditOps(x, y, m, n);
  printf(
      "minimal sequence of operations to translate %s -> %s has length %d.\n",
      x, y, result.ops_required);
  printf("minimal sequence of operations to translate %s -> %s is:\n", x, y);
  PrintEditSequence(result.op, x, y, 0, 0, m, n);
  free(x);
  free(y);
  free(result.dp);
  free(result.op);
}
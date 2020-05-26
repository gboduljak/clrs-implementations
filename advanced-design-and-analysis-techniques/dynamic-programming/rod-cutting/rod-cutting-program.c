#include "rod-cutting.h"
#include "stdio.h"
#include "stdlib.h"

int main() {
  int length;
  scanf("%d", &length);
  int i;
  int *p = malloc(sizeof(int) * (length + 1));
  for (i = 1; i <= length; i++)
    scanf("%d", &p[i]);
  for (i = 0; i <= length; i++)
    printf("optimal value (memoised) for length %d is %d\n", i,
           MemoisedCutRod(p, i));
  for (i = 0; i <= length; i++)
    printf("optimal value (bottom-up) for length %d is %d\n", i,
           BottomUpCutRod(p, i));
  for (i = 0; i <= length; i++) {
    printf("optimal value for length %d is %d\n", i, BottomUpCutRod(p, i));
    printf("optimal cuts for length %d are: ", i);
    PrintCutRodSolution(p, i);
  }
  free(p);
}
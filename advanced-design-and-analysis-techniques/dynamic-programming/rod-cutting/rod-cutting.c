#include "rod-cutting.h"
#include "stdio.h"
#include "stdlib.h"

int Max(int a, int b) { return a <= b ? b : a; }

int MemoisedCutRodAux(int *p, int *r, int n) {
  if (r[n] >= 0)
    return r[n];

  int q = -1, i;

  if (n == 0)
    return q = 0;
  else
    for (i = 1; i <= n; i++)
      q = Max(q, p[i] + MemoisedCutRodAux(p, r, n - i));

  return r[n] = q;
}

int MemoisedCutRod(int *p, int n) {
  int i;
  int *r = malloc(sizeof(int) * (n + 1));
  for (i = 0; i <= n; i++)
    r[i] = -1;
  int solution = MemoisedCutRodAux(p, r, n);
  free(r);
  return solution;
}

int BottomUpCutRod(int *p, int n) {
  int j, i, q;
  int *r = malloc(sizeof(int) * (n + 1));

  r[0] = 0;

  for (j = 1; j <= n; j++) {
    q = -1;
    for (i = 1; i <= j; i++)
      q = Max(q, p[i] + r[j - i]);
    r[j] = q;
  }
  return r[n];
}

cut_rod_result ExtendedBottomUpCutRod(int *p, int n) {
  cut_rod_result result;
  int j, i, q;
  int *r = malloc(sizeof(int) * (n + 1));
  int *s = malloc(sizeof(int) * (n + 1));

  result.r = r;
  result.s = s;

  r[0] = 0;

  for (j = 1; j <= n; j++) {
    q = -1;
    for (i = 1; i <= j; i++) {
      if (q < p[i] + r[j - i])
        q = p[i] + r[j - i], s[j] = i;
    }
    r[j] = q;
  }

  return result;
}

void PrintCutRodSolution(int *p, int n) {
  cut_rod_result result = ExtendedBottomUpCutRod(p, n);
  int *s = result.s;
  while (n > 0)
    printf("|%d|", s[n]), n -= s[n];
  printf("\n");
}
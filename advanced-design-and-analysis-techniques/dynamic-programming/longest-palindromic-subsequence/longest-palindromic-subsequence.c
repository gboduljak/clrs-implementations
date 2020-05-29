#include "../longest-common-subsequence/longest-common-subsequence.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

char *strrev(char *str) {
  char *p1, *p2;

  if (!str || !*str)
    return str;
  for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2) {
    *p1 ^= *p2;
    *p2 ^= *p1;
    *p1 ^= *p2;
  }
  return str;
}

int main() {
  int i, j, n;
  scanf("%d", &n);
  char *input = (char *)malloc(sizeof(char) * (n + 1));
  char *string = (char *)malloc(sizeof(char) * (n + 2));
  char *reversed_string = (char *)malloc(sizeof(char) * (n + 2));
  scanf("%s", input);
  // 1 based indexed, append dummy character to input
  strcpy(string, ".");
  strcat(string, input);
  strcpy(reversed_string, string);
  strrev(reversed_string);
  lcs_result result = LcsLength(string, reversed_string, n, n);
  printf("longest palindromic subsequence length: %d\n", result.length);
  printf("longest palindromic subsequence is: ");
  PrintLcs(result.b, string, reversed_string, n, n);
  printf("\n");
}
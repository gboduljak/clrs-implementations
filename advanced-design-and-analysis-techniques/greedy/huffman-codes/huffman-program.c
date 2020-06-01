#include "huffman.h"
#include "stdio.h"
#include "stdlib.h"
int main() {
  int n, i;
  scanf("%d", &n);
  char *c = (char *)malloc(sizeof(char) * (n + 1));
  int *f = (int *)malloc(sizeof(int) * (n + 1));

  scanf("%s", c);

  for (i = 0; i < n; i++)
    scanf("%d", &f[i]);

  huffman_code_node *huffman_code = Huffman(c, f, n);
  printf("the resulting huffman code tree is: \n");
  PrintHuffmanCode(huffman_code);
}
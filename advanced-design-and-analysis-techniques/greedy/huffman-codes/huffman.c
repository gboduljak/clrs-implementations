#include "huffman.h"
#include "../../../data-structures/heaps/min-priority-queue.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

huffman_code_node *AllocateHuffmanNode(int freq, int id) {
  huffman_code_node *node =
      (huffman_code_node *)malloc(sizeof(huffman_code_node));
  node->left = NULL;
  node->right = NULL;
  node->freq = freq;
  node->character = '\0';
  node->id = id;
  return node;
}

huffman_code_node *Huffman(char *c, int *f, int n) {
  huffman_code_node **nodes_storage = malloc(sizeof(huffman_code_node *) * 512);
  priority_queue *q = AllocateMinPq(512);
  int i;
  int k = 256;

  for (i = 0; i < n; i++) {
    nodes_storage[(int)c[i]] = AllocateHuffmanNode(f[i], (int)c[i]);
    nodes_storage[(int)c[i]]->character = c[i];
    MinPqInsert(q, (int)c[i], f[i]);
  }

  for (i = 1; i < n; i++) {
    priority_queue_element *X = MinPqExtractMin(q);
    priority_queue_element *Y = MinPqExtractMin(q);
    huffman_code_node *x = nodes_storage[X->id];
    huffman_code_node *y = nodes_storage[Y->id];
    huffman_code_node *z = AllocateHuffmanNode(x->freq + y->freq, k);
    z->left = x;
    z->right = y;
    nodes_storage[k] = z;
    MinPqInsert(q, k, z->freq);
    k++;
  }

  priority_queue_element *R = MinPqExtractMin(q);
  return nodes_storage[R->id];
}

char *concat(const char *s1, const char *s2) {
  char *result =
      malloc(strlen(s1) + strlen(s2) + 1); // +1 for the null-terminator
  strcpy(result, s1);
  strcat(result, s2);
  return result;
}

// inspired by
// https://stackoverflow.com/questions/36802354/print-binary-tree-in-a-pretty-way-using-c
void PrintHuffmanCodeRec(const char *prefix, huffman_code_node *root,
                         int is_left) {
  if (!root)
    return;

  printf("%s", prefix);
  printf("%s", is_left ? "├─0─" : "└─1─");

  if (root->character != '\0')
    printf("(%c:%d)\n", root->character, root->freq);
  else
    printf("(%d)\n", root->freq);

  char *next_level_prefix = concat(prefix, is_left ? "│   " : "    ");

  PrintHuffmanCodeRec(next_level_prefix, root->left, 1);
  PrintHuffmanCodeRec(next_level_prefix, root->right, 0);
}

void PrintHuffmanCode(huffman_code_node *root) {
  PrintHuffmanCodeRec("", root, 0);
}

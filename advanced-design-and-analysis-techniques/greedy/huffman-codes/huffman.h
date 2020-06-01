typedef struct huffman_code_node {
  int id;
  int freq;
  char character;
  struct huffman_code_node *left;
  struct huffman_code_node *right;
} huffman_code_node;

huffman_code_node *Huffman(char *c, int *f, int n);
void PrintHuffmanCode(huffman_code_node *root);
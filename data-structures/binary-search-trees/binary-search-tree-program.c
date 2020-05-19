#include "binary-search-tree.h"
#include <stdio.h>

int main() {
  binary_search_tree *root = AllocateTree(5);
  root->left = AllocateTree(1);
  root->right = AllocateTree(7);
  root->left->p = root;
  root->right->p = root;

  root->left->left = AllocateTree(0);
  root->left->right = AllocateTree(3);
  root->left->left->p = root->left;
  root->left->right->p = root->right;

  root->left->right->left = AllocateTree(2);
  root->left->right->left->p = root->left->right;

  root->right->left = AllocateTree(6);
  root->right->left->p = root->right;

  TreeInsert(root, AllocateTree(8));

  printf("inorder traversal: \n");
  InOrderTreeWalk(root);
  printf("\n");
  printf("maximum: %d\n", TreeMaximum(root)->key);
  printf("minimum: %d\n", TreeMinimum(root)->key);
}
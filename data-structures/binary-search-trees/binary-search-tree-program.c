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
  root->left->right->p = root->left;

  root->left->right->left = AllocateTree(2);
  root->left->right->left->p = root->left->right;

  root->right->left = AllocateTree(6);
  root->right->left->p = root->right;

  TreeInsert(root, AllocateTree(8));
  TreeInsert(root, AllocateTree(9));

  printf("inorder traversal: \n");
  InOrderTreeWalk(root);
  printf("\n");
  printf("maximum: %d\n", TreeMaximum(root)->key);
  printf("minimum: %d\n", TreeMinimum(root)->key);
  printf("performing deletions ...\n");
  TreeDelete(root, TreeSearch(root, 3));
  TreeDelete(root, TreeSearch(root, 5));
  TreeDelete(root, TreeSearch(root, 8));
  InOrderTreeWalk(root);
  printf("deleting root...\n");
  TreeDelete(root, root);
  InOrderTreeWalk(root);
}
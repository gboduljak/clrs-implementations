#include "red-black-tree.h"
#include <stdio.h>

int main() {
  rb_tree *root = AllocateRbTree(11);
  root->color = black;

  rb_tree *two = AllocateRbTreeNode(root, 2);
  two->color = red;
  rb_tree *fourteen = AllocateRbTreeNode(root, 14);
  fourteen->color = black;

  root->left = two;
  two->p = root;
  root->right = fourteen;
  fourteen->p = root;

  rb_tree *one = AllocateRbTreeNode(root, 1);
  one->color = black;
  rb_tree *seven = AllocateRbTreeNode(root, 7);
  seven->color = black;

  two->left = one;
  two->right = seven;
  one->p = two;
  seven->p = two;

  rb_tree *five = AllocateRbTreeNode(root, 5);
  five->color = red;
  seven->left = five;
  five->p = seven;

  rb_tree *eight = AllocateRbTreeNode(root, 8);
  eight->color = red;
  seven->right = eight;
  eight->p = seven;

  rb_tree *fifteen = AllocateRbTreeNode(root, 15);
  fifteen->color = red;
  fourteen->right = fifteen;
  fifteen->p = fourteen;

  RbInsert(root, AllocateRbTreeNode(root, 4));
  root = root->root;
  printf("hardcoded tree \n");
  RbTraverse(root, root);

  RbDelete(root, two);
  RbDelete(root, fourteen);
  RbDelete(root, root);
  printf("with deleted 2, 14, 7 \n");
  root = root->root;

  RbTraverse(root, root);
  RbDelete(root, five);
  printf("with deleted 5 \n");
  RbTraverse(root, root);

  printf("with deleted 4 \n");
  RbDelete(root, RbTreeSearch(root, root, 4));

  RbTraverse(root, root);
  return 0;
}
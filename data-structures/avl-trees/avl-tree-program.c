#include "avl-tree.h"
#include <stdio.h>
#include <stdlib.h>
int main() {
  avl_tree *tree = AllocateAvlTree();
  int i;
  for (i = 1; i <= 9; i++) {
    AvlInsert(tree, AllocateAvlNode(i));
    printf("%d\n", IsAvl(tree->root));
  }

  for (i = 1; i <= 9; i++) {
    AvlDelete(tree, AvlTreeSearch(tree->root, i));
    if (i != 9)
      printf("%d\n", IsAvl(tree->root));
  }
}
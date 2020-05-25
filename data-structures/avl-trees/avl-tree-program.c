#include "avl-tree.h"
#include <stdlib.h>
#include <stdio.h>
int main()
{
  avl_tree *tree = AllocateAvlTree();
  int i;
  for (i = 1; i <= 9; i++)
  {
    AvlInsert(tree, AllocateAvlNode(i));
    printf("%d\n", IsAvl(tree->root));
  }

  // for (i = 1; i <= 9; i++)
  // {
  //   root = AvlDelete(root, AvlTreeSearch(root, root, i));
  //   if (i != 9)
  //     printf("%d\n", IsAvl(root, root));
  // }

  i = 4;
}
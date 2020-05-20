#include "binary-search-tree.h"
#include "stdio.h"
#include "stdlib.h"

binary_search_tree *AllocateTree(int k)
{
  binary_search_tree *root =
      (binary_search_tree *)malloc(sizeof(binary_search_tree));
  root->key = k;
  root->left = NULL;
  root->right = NULL;
  root->p = NULL;
  return root;
}

void DeallocateTree(binary_search_tree *tree)
{
  if (!tree)
    return;
  DeallocateTree(tree->left);
  DeallocateTree(tree->right);
  free(tree);
}

void InOrderTreeWalk(binary_search_tree *x)
{
  if (!x)
    return;
  InOrderTreeWalk(x->left);
  printf("%d ", x->key);
  InOrderTreeWalk(x->right);
}

binary_search_tree *TreeSearch(binary_search_tree *x, int k)
{
  if (!x)
    return x;
  if (x->key == k)
    return x;
  return (k < x->key) ? TreeSearch(x->left, k) : TreeSearch(x->right, k);
}

binary_search_tree *TreeMinimum(binary_search_tree *x)
{
  if (!x)
    return x;
  while (x->left)
    x = x->left;
  return x;
}

binary_search_tree *TreeMaximum(binary_search_tree *x)
{
  if (!x)
    return x;
  while (x->right)
    x = x->right;
  return x;
}

binary_search_tree *TreeSuccessor(binary_search_tree *x)
{
  if (x->right)
    return TreeMinimum(x->right);
  binary_search_tree *y = x->p;
  while (y && x == y->right)
    x = y, y = y->p;
  return y;
}

binary_search_tree *TreePredecessor(binary_search_tree *x)
{
  if (x->left)
    return TreeMaximum(x->left);
  binary_search_tree *y = x->p;
  while (y && y->left == x)
    x = y, y = y->p;
  return y;
}

void TreeInsert(binary_search_tree *T, binary_search_tree *z)
{
  binary_search_tree *y = NULL;
  binary_search_tree *x = T;
  while (x)
  {
    y = x;
    x = (z->key < x->key) ? x->left : x->right;
  }
  z->p = y;
  if (!y)
  {
    *T = *z;
    return;
  }
  if (z->key < y->key)
    y->left = z;
  else
    y->right = z;
}

int TreeSortIx;
void TraverseInOrderInto(binary_search_tree *x, int *A)
{
  if (!x)
    return;
  TraverseInOrderInto(x->left, A);
  A[TreeSortIx] = x->key;
  TreeSortIx++;
  TraverseInOrderInto(x->right, A);
}

void TreeSort(int *A, int length)
{
  if (!length)
    return;
  int i = 0;
  binary_search_tree *tree = AllocateTree(A[0]);
  for (i = 1; i < length; i++)
    TreeInsert(tree, AllocateTree(A[i]));
  TreeSortIx = 0;
  TraverseInOrderInto(tree, A);
  DeallocateTree(tree);
}

void Transplant(binary_search_tree *T, binary_search_tree *u, binary_search_tree *v)
{
  if (!(u->p))
  {
    *T = *v;
    return;
  }
  if (u == u->p->left)
    u->p->left = v;
  else
    u->p->right = v;
  if (v)
    v->p = u->p;
}

void TreeDelete(binary_search_tree *T, binary_search_tree *z)
{
  if (z->left == NULL)
  {
    Transplant(T, z, z->right);
    return;
  }
  if (z->right == NULL)
  {
    Transplant(T, z, z->left);
    return;
  }
  binary_search_tree *y = TreeMinimum(z->right);
  int temp = y->key;
  z->key = y->key;
  y->key = temp;
  TreeDelete(T, y);
}
#include "avl-tree.h"
#include "stdlib.h"

avl_tree *AllocateAvlTree() {
  avl_tree *tree = (avl_tree *)malloc(sizeof(avl_tree));
  tree->root = NULL;
  return tree;
}

avl_node *AllocateAvlNode(int key) {
  avl_node *node = (avl_node *)malloc(sizeof(avl_node));
  node->left = NULL;
  node->right = NULL;
  node->p = NULL;
  node->key = key;
  node->height = 0;
  return node;
}

void DeallocateAvlNode(avl_node *node) {
  if (!node)
    return;
  DeallocateAvlNode(node->left);
  DeallocateAvlNode(node->right);
  free(node);
}

void DeallocateAvlTree(avl_tree *tree) {
  DeallocateAvlNode(tree->root);
  free(tree);
}

int AvlHeight(avl_node *node) { return node ? node->height : -1; }

int IsAvlBalanced(avl_node *node) {
  if (!node)
    return 1;

  return abs(AvlHeight(node->left) - AvlHeight(node->right)) <= 1;
}

int IsLeftHeavy(avl_node *node) {
  if (!node)
    return 0;

  return AvlHeight(node->left) - AvlHeight(node->right) == 2;
}

int IsRightHeavy(avl_node *node) {
  if (!node)
    return 0;

  return AvlHeight(node->right) - AvlHeight(node->left) == 2;
}

int IsAvl(avl_node *node) {
  if (!node)
    return 1;

  int left_avl = IsAvl(node->left);
  int right_avl = IsAvl(node->right);
  UpdateHeight(node);
  return left_avl && right_avl && IsAvlBalanced(node);
}

void BstInsert(avl_node *root, avl_node *node) {
  if (node->key <= root->key && !root->left) {
    root->left = node;
    node->p = root;
    return;
  }
  if (node->key >= root->key && !root->right) {
    root->right = node;
    node->p = root;
    return;
  }
  if (node->key <= root->key)
    BstInsert(root->left, node);
  else
    BstInsert(root->right, node);
}

avl_node *AvlTreeSearch(avl_node *x, int k) {
  if (!x)
    return x;
  if (x->key == k)
    return x;
  return (k < x->key) ? AvlTreeSearch(x->left, k) : AvlTreeSearch(x->right, k);
}

int Max(int a, int b) { return a <= b ? b : a; }
void UpdateHeight(avl_node *node) {
  if (!node)
    return;
  node->height = Max(AvlHeight(node->left), AvlHeight(node->right)) + 1;
}

void AvlInsert(avl_tree *tree, avl_node *node) {
  if (!tree->root) {
    tree->root = node;
    return;
  }
  BstInsert(tree->root, node);
  UpdateHeight(node);
  AvlRebalance(tree, node->p);
}

void RotateLeft(avl_tree *tree, avl_node *x) {
  avl_node *y = x->right;
  y->p = x->p;

  if (!(y->p))
    tree->root = y;
  else {
    if (y->p->left == x)
      y->p->left = y;
    else
      y->p->right = y;
  }
  x->right = y->left;
  if (x->right)
    x->right->p = x;

  y->left = x;
  x->p = y;
  UpdateHeight(x);
  UpdateHeight(y);
}

void RotateRight(avl_tree *tree, avl_node *x) {
  avl_node *y = x->left;
  y->p = x->p;

  if (!(y->p))
    tree->root = y;
  else {
    if (y->p->left == x)
      y->p->left = y;
    else
      y->p->right = y;
  }
  x->left = y->right;
  if (x->left)
    x->left->p = x;

  y->right = x;
  x->p = y;
  UpdateHeight(x);
  UpdateHeight(y);
}

void AvlRebalance(avl_tree *tree, avl_node *x) {
  while (x) {
    UpdateHeight(x->left);
    UpdateHeight(x->right);
    UpdateHeight(x);

    if (IsLeftHeavy(x)) {
      if (AvlHeight(x->left->left) < AvlHeight(x->left->right)) {
        // Case 4
        RotateLeft(tree, x->left);
        RotateRight(tree, x);
      } else {
        // Case 3
        RotateRight(tree, x);
      }
    } else if (IsRightHeavy(x)) {
      if (AvlHeight(x->right->left) > AvlHeight(x->right->right)) {
        // Case 2
        RotateRight(tree, x->right);
        RotateLeft(tree, x);
      } else {
        // Case 1
        RotateLeft(tree, x);
      }
    }
    x = x->p;
  }
}

int traversal_index;
void TraverseInOrderInto(avl_node *node, int *A) {
  if (!node)
    return;

  TraverseInOrderInto(node->left, A);
  A[++traversal_index] = node->key;
  TraverseInOrderInto(node->right, A);
}

void AvlSort(int *A, int length) {
  int i;
  avl_tree *tree = AllocateAvlTree();

  for (i = 0; i < length; i++)
    AvlInsert(tree, AllocateAvlNode(A[i]));

  traversal_index = -1;
  TraverseInOrderInto(tree->root, A);
  DeallocateAvlTree(tree);
}

void AvlTransplant(avl_tree *tree, avl_node *u, avl_node *v) {
  if (!(u->p)) {
    tree->root = v;
    return;
  }
  if (u == u->p->left)
    u->p->left = v;
  else
    u->p->right = v;
  if (v)
    v->p = u->p;
}

avl_node *AvlTreeMinimum(avl_node *x) {
  if (!x)
    return x;
  while (x->left)
    x = x->left;
  return x;
}

void AvlDelete(avl_tree *tree, avl_node *z) {
  if (tree->root == z && !tree->root->left && !tree->root->right) {
    tree->root = NULL;
    return;
  }

  if (z->left == NULL) {
    AvlTransplant(tree, z, z->right);
    AvlRebalance(tree, z->p);
    return;
  }
  if (z->right == NULL) {
    AvlTransplant(tree, z, z->left);
    AvlRebalance(tree, z->p);
    return;
  }
  avl_node *y = AvlTreeMinimum(z->right);
  int temp = y->key;
  z->key = y->key;
  y->key = temp;
  AvlDelete(tree, y);
}
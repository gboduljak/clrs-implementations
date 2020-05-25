#include "red-black-tree.h"
#include "stdio.h"
#include "stdlib.h"

rb_tree *AllocateRbTree(int key) {
  rb_tree *tree = (rb_tree *)malloc(sizeof(rb_tree));
  rb_tree *nil = (rb_tree *)malloc(sizeof(rb_tree));
  tree->p = nil;
  tree->left = nil;
  tree->right = nil;
  tree->nil = nil;
  tree->key = key;
  tree->root = tree;
  return tree;
}

rb_tree *AllocateRbTreeNode(rb_tree *root, int key) {
  rb_tree *tree = AllocateRbTree(key);
  tree->nil = root->nil;
  tree->left = root->nil;
  tree->right = root->nil;
  tree->p = root->nil;
  tree->key = key;
  return tree;
}

void RotateLeft(rb_tree *T, rb_tree *x) {
  rb_tree *y = x->right;
  x->right = y->left;
  if (y->left != T->nil)
    y->left->p = x;
  y->p = x->p;

  if (x->p == T->nil)
    T->root = y;
  else if (x == x->p->left)
    x->p->left = y;
  else
    x->p->right = y;

  y->left = x;
  x->p = y;
}

void RotateRight(rb_tree *T, rb_tree *y) {
  rb_tree *x = y->left;
  y->left = x->right;

  if (x->right != T->nil)
    x->right->p = y;

  x->p = y->p;
  if (y->p == T->nil)
    T->root = x;
  else if (y == y->p->left)
    y->p->left = x;
  else
    y->p->right = x;

  x->right = y;
  y->p = x;
}

void RbInsert(rb_tree *T, rb_tree *z) {
  rb_tree *y = T->nil;
  rb_tree *x = T->root;

  while (x != T->nil) {
    y = x;
    if (z->key < x->key)
      x = x->left;
    else
      x = x->right;
  }

  z->p = y;
  if (y == T->nil)
    T->root = z;
  else if (z->key < y->key)
    y->left = z;
  else
    y->right = z;

  z->left = T->nil;
  z->right = T->nil;
  z->color = red;

  RbInsertFixup(T, z);
}

void RbInsertFixup(rb_tree *T, rb_tree *z) {
  while (z->p->color == red) {
    if (z->p == z->p->p->left) {
      rb_tree *y = z->p->p->right; // famous uncle

      if (y->color == red) // (Case 1), known as red uncle fix
      {
        z->p->p->color = red;
        z->p->color = black;
        y->color = black;
        z = z->p->p;
      } else {
        if (z == z->p->right) // (Case 2)
        {
          z = z->p;
          RotateLeft(T, z); // (Reduction to (Case 3))
        }
        z->p->color = black; // (Case 3)
        z->p->p->color = red;
        RotateRight(T, z->p->p);
      }
    } else {
      rb_tree *y = z->p->p->left; // famous uncle

      if (y->color == red) // (Case 1), known as red uncle fix
      {
        z->p->p->color = red;
        z->p->color = black;
        y->color = black;
        z = z->p->p;
      } else {
        if (z == z->p->left) // (Case 2)
        {
          z = z->p;
          RotateRight(T, z); // (Reduction to (Case 3))
        }
        z->p->color = black; // (Case 3)
        z->p->p->color = red;
        RotateLeft(T, z->p->p);
      }
    }
  }
  T->root->color = black;
}

void RbTransplant(rb_tree *T, rb_tree *u, rb_tree *v) {
  if (u->p == T->nil) {
    T->root = v;
    return;
  }

  if (u == u->p->left)
    u->p->left = v;
  else
    u->p->right = v;

  v->p = u->p;
}

rb_tree *RbTreeMinimum(rb_tree *T, rb_tree *x) {
  if (x == T->nil)
    return x;
  while (x->left != T->nil)
    x = x->left;
  return x;
}

void RbDeleteFixup(rb_tree *T, rb_tree *x) {
  rb_tree *w = NULL;
  while (x != T->root && x->color == black) {
    if (x == x->p->left) {
      w = x->p->right;
      if (w->color == red) // (Case 1) - red sibling case
      {
        w->color = black;
        x->p->color = red;
        RotateLeft(T, x->p);
        w = x->p->right;
      }
      if (w->left->color == black &&
          w->right->color == black) // (Case 2) - black sibling black children
      {
        w->color = red;
        x = x->p;
      } else {
        if (w->left->right->color ==
            black) // (Case 3) - black sibling, red left sibling child
        {
          w->left->color = black;
          w->color = red;
          RotateRight(T, w);
          w = x->p->right; // Reduced to (Case 4) - black sibling, black left
                           // sibling child
        }
        w->color = x->p->color;
        x->p->color = black;
        w->right->color = black;
        RotateLeft(T, x->p);
        x = T->root; // We are done this makes fixup stop
      }
    } else {
      w = x->p->left;
      if (w->color == red) // (Case 1) - red sibling case
      {
        w->color = black;
        x->p->color = red;
        RotateRight(T, x->p);
        w = x->p->left;
      }
      if (w->right->color == black &&
          w->left->color == black) // (Case 2) - black sibling black children
      {
        w->color = red;
        x = x->p;
      } else {
        if (w->right->left->color ==
            black) // (Case 3) - black sibling, red left sibling child
        {
          w->right->color = black;
          w->color = red;
          RotateLeft(T, w);
          w = x->p->left; // Reduced to (Case 4) - black sibling, black left
                          // sibling child
        }
        w->color = x->p->color;
        x->p->color = black;
        w->left->color = black;
        RotateRight(T, x->p);
        x = T->root; // We are done this makes fixup stop
      }
    }
  }
  x->color = black;
}

void RbDelete(rb_tree *T, rb_tree *z) {
  rb_tree *y = z;
  rb_tree *x = T->nil;

  int y_original_color = y->color;

  if (z->left == T->nil) {
    x = z->right;
    RbTransplant(T, z, z->right);
  } else if (z->right == T->nil) {
    x = z->left;
    RbTransplant(T, z, z->left);
  } else {
    y = RbTreeMinimum(T, z->right);
    y_original_color = y->color;
    x = y->right;

    if (y->p == z)
      x->p = y;
    else {
      RbTransplant(T, y, y->right); // replace y with y->right
      y->right = z->right;          // prepare y to replace z
      y->right->p = y;
    }
    // y is ready to replace z
    RbTransplant(T, z, y); // is replaced by y

    y->left = z->left;
    y->left->p = y;
    y->color = z->color;
  }

  if (y_original_color == black)
    RbDeleteFixup(T, x);
}

rb_tree *RbTreeSearch(rb_tree *T, rb_tree *x, int k) {
  if (x == T->nil)
    return x;
  if (x->key == k)
    return x;
  return (k < x->key) ? RbTreeSearch(T, x->left, k)
                      : RbTreeSearch(T, x->right, k);
}

void RbTraverse(rb_tree *T, rb_tree *x) {
  if (x == T->nil)
    return;

  RbTraverse(T, x->left);
  printf("%d \n", x->key);
  RbTraverse(T, x->right);
}
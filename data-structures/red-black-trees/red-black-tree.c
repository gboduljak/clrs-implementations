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
        z->p->color = black;
        z->p->p->color = red;
        RotateRight(T, z->p->p);
      }
    } else {
      rb_tree *y = z->p->p->left; // famous uncle

      // reverse
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
        z->p->color = black;
        z->p->p->color = red;
        RotateLeft(T, z->p->p);
      }
    }
  }
  T->root->color = black;
}
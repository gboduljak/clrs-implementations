
#define red 0
#define black 1

typedef struct rb_tree {
  int key;
  int color;
  struct rb_tree *left;
  struct rb_tree *right;
  struct rb_tree *root;
  struct rb_tree *p;
  struct rb_tree *nil;
} rb_tree;

rb_tree *RbTreeMinimum(rb_tree *T, rb_tree *x);
rb_tree *AllocateRbTree(int key);
rb_tree *AllocateRbTreeNode(rb_tree *root, int key);
void RbTraverse(rb_tree *T, rb_tree *x);
void RotateLeft(rb_tree *T, rb_tree *x);
void RotateRight(rb_tree *T, rb_tree *y);
void RbInsert(rb_tree *T, rb_tree *z);
void RbInsertFixup(rb_tree *T, rb_tree *z);
void RbDelete(rb_tree *T, rb_tree *z);
void RbTransplant(rb_tree *T, rb_tree *u, rb_tree *v);
void RbDeleteFixup(rb_tree *T, rb_tree *x);
rb_tree *RbTreeSearch(rb_tree *T, rb_tree *x, int k);
#define balanced 0
#define right_heavy 2
#define left_heavy -2

typedef struct avl_node {
  int key;
  int height;
  struct avl_node *p;
  struct avl_node *left;
  struct avl_node *right;
} avl_node;

typedef struct avl_tree {
  avl_node *root;
} avl_tree;

int IsAvlBalanced(avl_node *node);
int IsRightHeavy(avl_node *node);
int IsLeftHeavy(avl_node *node);
int IsAvl(avl_node *node);

int AvlHeight(avl_node *node);
void UpdateHeight(avl_node *node);
avl_tree *AllocateAvlTree();
avl_node *AllocateAvlNode(int key);
void DeallocateAvlTree(avl_tree *tree);

avl_node *AvlTreeSearch(avl_node *node, int key);
void AvlDelete(avl_tree *tree, avl_node *z);
void AvlInsert(avl_tree *tree, avl_node *node);
void AvlRebalance(avl_tree *tree, avl_node *x);
void AvlSort(int *A, int length);
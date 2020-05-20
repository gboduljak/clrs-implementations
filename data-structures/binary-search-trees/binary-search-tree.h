typedef struct binary_search_tree {
  int key;
  struct binary_search_tree *left;
  struct binary_search_tree *right;
  struct binary_search_tree *p;
} binary_search_tree;

void InOrderTreeWalk(binary_search_tree *x);
void TraverseInOrderInto(binary_search_tree *x, int *A);

binary_search_tree *AllocateTree(int k);
void DeallocateTree(binary_search_tree *x);
binary_search_tree *TreeSearch(binary_search_tree *x, int k);
binary_search_tree *TreeMinimum(binary_search_tree *x);
binary_search_tree *TreeMaximum(binary_search_tree *x);
binary_search_tree *TreePredecessor(binary_search_tree *x);
binary_search_tree *TreeSuccessor(binary_search_tree *x);
void TreeDelete(binary_search_tree *T, binary_search_tree *x);
void TreeInsert(binary_search_tree *T, binary_search_tree *z);
void TreeSort(int *A, int length);
typedef struct dsu_node {
  int rank;
  int key;
  struct dsu_node *p;
} dsu_node;

typedef struct dsu {
  int length;
  dsu_node *nodes;
} dsu;

dsu *AllocateDsu(int length);
void DeallocateDsu(dsu *dsu);

dsu_node *FindSet(dsu_node *x);
void Union(dsu_node *x, dsu_node *y);
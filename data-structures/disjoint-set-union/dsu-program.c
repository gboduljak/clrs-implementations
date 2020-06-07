#include "dsu.h"
#include "stdio.h"
#include "stdlib.h"

int main() {
  int i = 0;
  dsu *dsu = AllocateDsu(10);
  Union(dsu->nodes + 1, dsu->nodes + 2);
  Union(&dsu->nodes[2], &dsu->nodes[3]);
  Union(&dsu->nodes[3], &dsu->nodes[4]);

  for (i = 1; i < 5; i++) {
    dsu_node *set = FindSet(&dsu->nodes[i]);
    printf("parent of %d is %d with rank %d\n", i, set->p->key, set->p->rank);
  }

  DeallocateDsu(dsu);
  return 0;
}
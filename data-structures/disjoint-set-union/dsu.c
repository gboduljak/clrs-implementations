#include "dsu.h"
#include "stdlib.h"

dsu *AllocateDsu(int length) {
  int i;
  dsu *dsu = malloc(sizeof(dsu));
  dsu->nodes = malloc(sizeof(dsu_node) * (length));
  for (i = 0; i < length; i++) {
    dsu->nodes[i].key = i;
    dsu->nodes[i].rank = 0;
    dsu->nodes[i].p = &dsu->nodes[i];
  }
  dsu->length = length;
  return dsu;
}

void DeallocateDsu(dsu *dsu) {
  free(dsu->nodes);
  free(dsu);
}

dsu_node *FindSet(dsu_node *x) {
  dsu_node *p, *y;
  while (x != x->p)
    x = x->p;

  p = x;
  while (x != x->p) {
    y = x;
    x = x->p;
    y->p = p;
  }
  return p;
}

void Link(dsu_node *x, dsu_node *y) {
  if (x->rank > y->rank)
    y->p = x;
  else {
    x->p = y;
    if (x->rank == y->rank)
      y->rank++;
  }
}

void Union(dsu_node *x, dsu_node *y) { Link(FindSet(x), FindSet(y)); }
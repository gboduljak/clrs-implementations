#include "../graph.h"

#ifndef INITIALIZE_SINGLE_SOURCE_H
#define INITIALIZE_SINGLE_SOURCE_H
typedef struct single_source_structs {
  int *d;
  int *p;
} single_source_structs;

single_source_structs InitializeSingleSource(graph *g, int s);
#endif

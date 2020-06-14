#include "../../initialize-single-source.h"

typedef struct transitive_closure_result {
  int **t;
} transitive_closure_result;

transitive_closure_result TransitiveClosure(graph *g);
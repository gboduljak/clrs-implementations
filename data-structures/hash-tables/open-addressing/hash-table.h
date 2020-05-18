#include "hash-function.h"

typedef struct hash_table {
  bigint *T;
  int *S;
  int *V;
  int (*hash)(bigint, int, int);
  int m;
} hash_table;

typedef struct hash_table_op_result {
  int successful;
  int value;
} hash_table_op_result;

hash_table *AllocateHashTable(int (*hash)(bigint, int, int), int m);
void DeallocateHashTable(hash_table *hash_table);
hash_table_op_result HashInsert(hash_table *hash_table, bigint key, int value);
hash_table_op_result HashLookup(hash_table *hash_table, bigint key);
hash_table_op_result HashDelete(hash_table *hash_table, bigint key);
#include "hash-function.h"
#include "linked-list.h"

typedef struct hash_table {
  linked_list **T;
  int (*hash)(bigint, int);
  int m;
} hash_table;

hash_table *AllocateHashTable(int (*hash)(bigint, int), int m);
void DeallocateHashTable(hash_table *hash_table);
void HashInsert(hash_table *hash_table, bigint key, int value);
linked_list_node *HashLookup(hash_table *hash_table, bigint key);
void HashDelete(hash_table *hash_table, bigint key);
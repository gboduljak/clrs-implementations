#include "hash-table.h"
#include <stdlib.h>

hash_table *AllocateHashTable(int (*hash)(bigint, int), int size) {
  int i;
  hash_table *table = malloc(sizeof(hash_table));
  table->T = malloc(sizeof(linked_list *) * size);
  table->m = size;
  table->hash = hash;

  for (i = 0; i < size; i++)
    table->T[i] = AllocateLinkedList();

  return table;
}

void DeallocateHashTable(hash_table *hash_table) {
  int i;
  for (i = 0; i < hash_table->m; i++)
    DellocateLinkedList(hash_table->T[i]);

  free(hash_table->T);
  free(hash_table);
}

void HashInsert(hash_table *hash_table, bigint key, int value) {
  int k = hash_table->hash(key, hash_table->m);
  ListInsert(hash_table->T[k], key, value);
}

linked_list_node *HashLookup(hash_table *hash_table, bigint key) {
  int k = hash_table->hash(key, hash_table->m);
  linked_list_node *node = ListSearch(hash_table->T[k], key);
  return node;
}

void HashDelete(hash_table *hash_table, bigint key) {
  int k = hash_table->hash(key, hash_table->m);
  linked_list_node *node = HashLookup(hash_table, key);
  ListDelete(hash_table->T[k], node);
}

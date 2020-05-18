#include "hash-table.h"
#include <stdlib.h>

#define position_status_free 0
#define position_status_deleted 1
#define position_status_taken 2

hash_table *AllocateHashTable(int (*hash)(bigint, int, int), int size) {
  int i;
  hash_table *table = malloc(sizeof(hash_table));
  table->T = malloc(sizeof(bigint) * size);
  table->V = malloc(sizeof(int) * size);
  table->S = malloc(sizeof(int) * size);
  table->m = size;
  table->hash = hash;

  for (i = 0; i < size; i++)
    table->S[i] = position_status_free;

  return table;
}

void DeallocateHashTable(hash_table *hash_table) {
  int i;
  free(hash_table->T);
  free(hash_table);
}

hash_table_op_result HashInsert(hash_table *hash_table, bigint key, int value) {
  hash_table_op_result result;
  result.successful = 0;
  int i = 0;
  while (i < hash_table->m && !result.successful) {
    int j = hash_table->hash(key, i, hash_table->m);
    if (hash_table->S[j] != position_status_taken) {
      hash_table->T[j] = key;
      hash_table->V[j] = value;
      hash_table->S[j] = position_status_taken;
      result.successful = 1;
    } else
      i++;
  }
  return result;
}

hash_table_op_result HashLookup(hash_table *hash_table, bigint key) {
  hash_table_op_result result;
  result.successful = 0;
  int i = 0;

  while (i < hash_table->m && !result.successful) {
    int j = hash_table->hash(key, i, hash_table->m);

    if (hash_table->T[j] == key) {
      if (hash_table->S[j] == position_status_deleted) {
        result.value = -1;
        result.successful = 0;
        break;
      } else {
        result.value = hash_table->V[j];
        result.successful = 1;
      }
    } else
      i++;
  }
  return result;
}

hash_table_op_result HashDelete(hash_table *hash_table, bigint key) {
  hash_table_op_result result;
  result.successful = 0;
  int i = 0;

  while (i < hash_table->m && !result.successful) {
    int j = hash_table->hash(key, i, hash_table->m);
    if (hash_table->T[j] == key && hash_table->S[j] == position_status_taken) {
      hash_table->S[j] = position_status_deleted;
      result.successful = 1;
    } else
      i++;
  }
  return result;
}
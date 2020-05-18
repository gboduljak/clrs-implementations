#include "djb2.h"
#include "hash-table.h"
#include "stdio.h"

int main() {
  hash_table *table = AllocateHashTable(ProbeSequenceHash, 10);
  char *str1 = "Thomas H. Cormen";
  char *str2 = "Charles E. Leiserson";
  char *str3 = "Ronald L. Rivest";
  char *str4 = "Clifford Stein. T";

  HashInsert(table, djb2(str1), 1);
  HashInsert(table, djb2(str2), 2);
  HashInsert(table, djb2(str3), 3);
  HashInsert(table, djb2(str4), 4);

  hash_table_op_result lookup_result = HashLookup(table, djb2(str1));
  printf("key: %s, value:%d\n", str1, HashLookup(table, djb2(str1)).value);
  printf("key: %s, value:%d\n", str2, HashLookup(table, djb2(str2)).value);
  printf("key: %s, value:%d\n", str3, HashLookup(table, djb2(str3)).value);
  printf("key: %s, value:%d\n", str4, HashLookup(table, djb2(str4)).value);

  hash_table_op_result delete_result = HashDelete(table, djb2(str4));
  hash_table_op_result lookup_result_stein = HashLookup(table, djb2(str4));
  HashInsert(table, djb2(str4), 4);
  lookup_result_stein = HashLookup(table, djb2(str1));

  DeallocateHashTable(table);
  return 0;
}
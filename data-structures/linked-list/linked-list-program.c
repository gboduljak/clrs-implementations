#include "linked-list.h"
#include "stdio.h"

int main() {
  linked_list *list = AllocateLinkedList();
  ListInsert(list, 9);
  linked_list_node *to_delete = ListInsert(list, 16);
  ListInsert(list, 4);
  ListInsert(list, 1);
  ListDelete(list, to_delete);
  to_delete = ListSearch(list, 1);
  ListDelete(list, to_delete);
  DellocateLinkedList(list);
  return 0;
}
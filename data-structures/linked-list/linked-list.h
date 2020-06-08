#ifndef LINKED_LIST_H
#define LINKED_LIST_H
typedef struct linked_list_node {
  int key;
  struct linked_list_node *next;
  struct linked_list_node *prev;
} linked_list_node;

typedef struct linked_list {
  linked_list_node *nil;
  int length;
} linked_list;

linked_list *AllocateLinkedList();
void DellocateLinkedList();
linked_list_node *ListInsert(linked_list *list, int x);
linked_list_node *ListInsertBack(linked_list *list, int x);
linked_list_node *ListReplace(linked_list *list, linked_list_node *x,
                              linked_list *y);
linked_list_node *ListSearch(linked_list *list, int k);
void ListDelete(linked_list *list, linked_list_node *node);
#endif

#include "linked-list.h"
#include "stdlib.h"

linked_list *AllocateLinkedList() {
  linked_list *list = malloc(sizeof(linked_list));
  list->nil = malloc(sizeof(linked_list_node));
  list->nil->next = list->nil;
  list->nil->prev = list->nil;
  list->length = 0;
  return list;
}

void DellocateLinkedListNode(linked_list *list, linked_list_node *node) {
  if (node->next == list->nil) {
    free(node);
    return;
  }
  DellocateLinkedListNode(list, node->next);
  free(node);
}

void DellocateLinkedList(linked_list *list) {
  DellocateLinkedListNode(list, list->nil->next);
  free(list);
}

linked_list_node *ListInsert(linked_list *list, int x) {
  list->length++;
  linked_list_node *node = malloc(sizeof(linked_list_node));
  node->key = x;
  node->next = list->nil->next;
  list->nil->next->prev = node;
  list->nil->next = node;
  node->prev = list->nil;
  return node;
}

linked_list_node *ListSearch(linked_list *list, int k) {
  linked_list_node *x = list->nil->next;
  while (x != list->nil && x->key != k)
    x = x->next;
  return x;
}

void ListDelete(linked_list *list, linked_list_node *node) {
  list->length--;
  node->prev->next = node->next;
  node->next->prev = node->prev;
}
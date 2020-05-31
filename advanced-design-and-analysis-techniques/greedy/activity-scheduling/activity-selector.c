#include "activity-selector.h"
#include "stdio.h"

linked_list *RecursiveActivitySelector(linked_list *scheduled, int *s, int *f,
                                       int k, int n) {
  int m = k + 1;
  while (s[m] < f[k])
    m++;
  if (m >= n)
    return scheduled;
  ListInsert(scheduled, m);
  return RecursiveActivitySelector(scheduled, s, f, m, n);
}

linked_list *GreedyActivitySelector(int *s, int *f, int n) {
  linked_list *result = AllocateLinkedList();
  ListInsert(result, 0);
  int k = 0, m;

  for (m = 1; m < n; m++)
    if (s[m] >= f[k])
      ListInsert(result, m), k = m;

  return result;
}

void PrintSchedule(linked_list *list, linked_list_node *current) {
  if (current == list->nil)
    return;

  PrintSchedule(list, current->next);
  printf("perform activity: %d \n", current->key);
}
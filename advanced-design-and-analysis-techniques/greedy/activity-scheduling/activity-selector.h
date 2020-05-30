#include "../../../data-structures/linked-list/linked-list.h"

linked_list *RecursiveActivitySelector(linked_list *scheduled, int *s, int *f, int k, int n);
linked_list *GreedyActivitySelector(int *s, int *f, int n);
void PrintSchedule(linked_list *list, linked_list_node *current);
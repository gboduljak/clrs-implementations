#include "activity-selector.h"
#include "stdio.h"
#include "stdlib.h"

int main() {
  int n, i;
  scanf("%d", &n);

  int *s = (int *)malloc(sizeof(int) * n);
  int *f = (int *)malloc(sizeof(int) * n);

  for (i = 0; i < n; i++)
    scanf("%d", &s[i]);
  for (i = 0; i < n; i++)
    scanf("%d", &f[i]);

  // assumes the activities are sorted by finishing time in nondecreasing order
  linked_list *schedule = AllocateLinkedList();
  schedule = RecursiveActivitySelector(schedule, s, f, -1, n);
  schedule = GreedyActivitySelector(s, f, n);

  PrintSchedule(schedule, schedule->nil->next);
  DellocateLinkedList(schedule);
  free(s);
  free(f);
  return 0;
}
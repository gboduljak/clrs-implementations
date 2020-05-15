#include "bucket.h"
#include <stdlib.h>

bucket *Append(bucket *source, bucket *node) {
  if (!source)
    return node;

  node->next = source;
  source->previous = node;
  node->previous = NULL;
  return node;
}
bucket *AllocateBucket() { return (bucket *)malloc(sizeof(bucket)); }
bucket *InsertSortBucket(bucket *head) {
  if (!head)
    return head;
  if (!head->next) {
    bucket *result = AllocateBucket();
    result->value = head->value;
    free(head);
    return result;
  }

  bucket *sorted_tail = InsertSortBucket(head->next);

  double value = head->value;

  bucket *insertion_pos = sorted_tail;
  bucket *previous_pos = sorted_tail;
  while (insertion_pos && insertion_pos->value <= value) {
    previous_pos = insertion_pos;
    insertion_pos = insertion_pos->next;
  }
  if (!insertion_pos) {
    bucket *new_bucket = AllocateBucket();
    new_bucket->value = value;
    new_bucket->previous = previous_pos;
    previous_pos->next = new_bucket;
    return sorted_tail;
  }
  if (insertion_pos == sorted_tail)
    return Append(sorted_tail, head);

  bucket *new_bucket = AllocateBucket();
  new_bucket->value = value;
  new_bucket->previous = previous_pos;
  new_bucket->previous->next = new_bucket;
  new_bucket->next = insertion_pos;
  new_bucket->next->previous = new_bucket;
  sorted_tail->previous = NULL;
  free(head);
  return sorted_tail;
}
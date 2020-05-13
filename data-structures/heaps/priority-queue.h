#ifndef priority_queue_h
#define priority_queue_h
typedef struct priority_queue {
  int *heap;
  int *position_of_id;
  int *id_at_position;
  int heap_size;
  int size;
} priority_queue;

#endif
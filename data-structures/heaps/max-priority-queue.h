typedef struct pq_element {
  int id;
  int key;
} pq_element;

typedef struct max_priority_queue {
  int *heap;
  int *position_of_id;
  int *id_at_position;
  int heap_size;
  int size;
} max_priority_queue;

max_priority_queue *AllocateMaxPq(int size);
void DestroyMaxPq();

max_priority_queue *BuildMaxPq(int *ids, int *keys, int input_size,
                               int heap_size);
pq_element *MaxPqInsert(max_priority_queue *pq, int id, int key);
void MaxPqIncreaseKey(max_priority_queue *pq, int i, int new_key);
pq_element *MaxPqExtractMax(max_priority_queue *pq);

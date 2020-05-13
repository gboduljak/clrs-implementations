
#include "priority-queue.h"
#include "priority_queue_element.h"

priority_queue *AllocateMaxPq(int size);
void DestroyMaxPq();

priority_queue *BuildMaxPq(int *ids, int *keys, int input_size, int heap_size);
priority_queue_element *MaxPqInsert(priority_queue *pq, int id, int key);
void MaxPqIncreaseKey(priority_queue *pq, int i, int new_key);
priority_queue_element *MaxPqExtractMax(priority_queue *pq);

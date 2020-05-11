typedef struct
{
  int heap_size;
  int size;
  int *a;
} heap;

heap *AllocateMaxHeap(int size);
void DestroyMaxHeap(heap *heap);

int Parent(int i);
int Left(int i);
int Right(int i);

void MaxHeapify(heap *heap, int i);
void BuildMaxHeap(heap *heap);
int Max(heap *heap);
int ExtractMax(heap *heap);
void IncreaseKey(heap *heap, int i);
void MaxHeapInsert(heap *heap, int key);
void HeapSort(int *A, int size);
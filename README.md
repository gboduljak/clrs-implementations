## 👨‍💻 CLRS Implementations

This is a repository of pseudocode discussed in the main text of a classic - 📖Introduction to Algorithms, known as CLRS.
All implementations are written in C.

The folder structure resembles the book structure. Usually, implementations come with small auxiliary programs and simple test inputs.
For example, along with [heap implementation](https://github.com/gboduljak/clrs-implementations/blob/master/data-structures/heaps/max-heap.c) there is a small [heap program](https://github.com/gboduljak/clrs-implementations/blob/master/data-structures/heaps/max-heap-program.c) used to demonstrate heap operations.

Also, although the pseudocode in the book may not have the best variable naming, I have decided to respect it for the sake of consistency.

Here is a summary of pseudocode implemented so far:

- **Foundations (Chapters 2,3,4)** [🔗](https://github.com/gboduljak/clrs-implementations/tree/master/foundations)
  - InsertionSort
  - MergeSort
  - Maximum Subarray (Divide and Conquer, BruteForce)
- **Sorting and Order Statistics (Chapters 6,7,8,9)**

  - Max Heap [🔗](https://github.com/gboduljak/clrs-implementations/blob/master/data-structures/heaps/max-heap.c)
  - HeapSort [🔗](https://github.com/gboduljak/clrs-implementations/blob/master/data-structures/heaps/max-heap.c)
  - Max Priority Queue [🔗](https://github.com/gboduljak/clrs-implementations/blob/master/data-structures/heaps/max-priority-queue.c)
  - Min Priority Queue [🔗](https://github.com/gboduljak/clrs-implementations/blob/master/data-structures/heaps/min-priority-queue.c)
    - Implemented as Max Priority Queue with inverted keys
  - QuickSort (non-randomised) [🔗](https://github.com/gboduljak/clrs-implementations/blob/master/sorting/quick-sort/quicksort.c)
  - QuickSort (randomised) [🔗](https://github.com/gboduljak/clrs-implementations/blob/master/sorting/quick-sort/randomised-quicksort.c)
  - CountingSort [🔗](https://github.com/gboduljak/clrs-implementations/blob/master/sorting/counting-sort/counting-sort.c)
  - RadixSort [🔗](https://github.com/gboduljak/clrs-implementations/blob/master/sorting/radix-sort/radix-sort.c)
  - BucketSort [🔗](https://github.com/gboduljak/clrs-implementations/blob/master/sorting/bucket-sort/bucket-sort.c)
  - RandomisedSelect aka QuickSelect [🔗](https://github.com/gboduljak/clrs-implementations/blob/master/sorting/quick-sort/randomised-select.c)

- **Data Structures (Chapters 10, 11, 12, 13)**
  - Stack (array-based) [🔗](https://github.com/gboduljak/clrs-implementations/blob/master/data-structures/stack/stack.c)
  - Queue (wraparound array-based) [🔗](https://github.com/gboduljak/clrs-implementations/blob/master/data-structures/queue/queue.c)
  - Linked-List (implemented as doubly-linked and circular) [🔗](https://github.com/gboduljak/clrs-implementations/blob/master/data-structures/linked-list/linked-list.c)

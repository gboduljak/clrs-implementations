## 👨‍💻 CLRS Implementations

This is a repository of pseudocode implementations discussed in the main text of a classic - 📖 Introduction to Algorithms, known as CLRS.
All implementations are written in C.

The folder structure resembles the book structure. Usually, implementations come with small auxiliary programs and simple test inputs.
For example, along with [heap implementation](https://github.com/gboduljak/clrs-implementations/blob/master/data-structures/heaps/max-heap.c) there is a small [heap program](https://github.com/gboduljak/clrs-implementations/blob/master/data-structures/heaps/max-heap-program.c) used to demonstrate heap operations.

Also, although the pseudocode in the book may not have the best variable naming, I have decided to respect it for the sake of consistency.

Here is a table of contents of pseudocode implemented so far:

- **Foundations (Chapters 2, 3, 4)** [🔗](https://github.com/gboduljak/clrs-implementations/tree/master/foundations)
  - InsertionSort
  - MergeSort
  - Maximum Subarray (Divide and Conquer, BruteForce)
- **Sorting and Order Statistics (Chapters 6, 7, 8, 9)**

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

  - Stack
    - (array-based) [🔗](https://github.com/gboduljak/clrs-implementations/blob/master/data-structures/stack/stack.c)
    - (doubly-linked-list-based) [🔗](https://github.com/gboduljak/clrs-implementations/blob/master/data-structures/linked-list/stack.c)
  - Queue
    - (wraparound array-based) [🔗](https://github.com/gboduljak/clrs-implementations/blob/master/data-structures/queue/queue.c)
    - (doubly-linked-list-based) [🔗](https://github.com/gboduljak/clrs-implementations/blob/master/data-structures/linked-list/queue.c)
  - Linked-List (doubly-linked, circular) [🔗](https://github.com/gboduljak/clrs-implementations/blob/master/data-structures/linked-list/linked-list.c)
  - Hash Table
    - (chaining) [🔗](https://github.com/gboduljak/clrs-implementations/blob/master/data-structures/hash-tables/chaining/hash-table.c)
    - (open-addressing with double-hashing) [🔗](https://github.com/gboduljak/clrs-implementations/blob/master/data-structures/hash-tables/open-addressing/hash-table.c)
  - Binary Search Tree [🔗](https://github.com/gboduljak/clrs-implementations/blob/master/data-structures/binary-search-trees/binary-search-tree.c)
  - Red Black Tree [🔗](https://github.com/gboduljak/clrs-implementations/blob/master/data-structures/red-black-trees/red-black-tree.c)
    - Insertion
    - Deletion
  - AVL Tree [🔗](https://github.com/gboduljak/clrs-implementations/blob/master/data-structures/avl-trees/avl-tree.c)
    - Insertion
    - Deletion
    - AVL Sort

- **Advanced Design and Analysis Techniques (Chapters 15, 16)**
  - Dynamic Programming
    - rod cutting [🔗](https://github.com/gboduljak/clrs-implementations/blob/master/advanced-design-and-analysis-techniques/dynamic-programming/rod-cutting/rod-cutting.c)
    - matrix chain multiplication [🔗](https://github.com/gboduljak/clrs-implementations/blob/master/advanced-design-and-analysis-techniques/dynamic-programming/matrix-chain-multiplication/matrix-chain-multiply.c)
    - longest common subsequence [🔗](https://github.com/gboduljak/clrs-implementations/blob/master/advanced-design-and-analysis-techniques/dynamic-programming/longest-common-subsequence/longest-common-subsequence.c)
    - optimal binary search tree [🔗](https://github.com/gboduljak/clrs-implementations/blob/master/advanced-design-and-analysis-techniques/dynamic-programming/optimal-binary-search-tree/optimal-bst.c)
    - longest path in a dag [🔗](https://github.com/gboduljak/clrs-implementations/blob/master/advanced-design-and-analysis-techniques/dynamic-programming/longest-path-dag/longest-path.c)
    - longest palindromic subsequence [🔗](https://github.com/gboduljak/clrs-implementations/blob/master/advanced-design-and-analysis-techniques/dynamic-programming/longest-palindromic-subsequence/longest-palindromic-subsequence.c)
      - implemented as longest-common-subsequence(input, reversed(input)) 
    - printing neatly [🔗](https://github.com/gboduljak/clrs-implementations/blob/master/advanced-design-and-analysis-techniques/dynamic-programming/printing-neatly/printing-neatly.c)
      - also known as a variant of the word wrap problem
     - simplified-edit-distance [🔗](https://github.com/gboduljak/clrs-implementations/blob/master/advanced-design-and-analysis-techniques/dynamic-programming/simplified-edit-distance/simplified-edit-distance.c)
  - Greedy
    - activity scheduling [🔗](https://github.com/gboduljak/clrs-implementations/blob/master/advanced-design-and-analysis-techniques/greedy/activity-scheduling/activity-selector.c)
    - interval graph coloring(scheduling) - exercise 16.1.4 
      - We are given **n** activities to be held in some lecture halls. For each activity we know its starting time, finishing time and id. Any activity can take place in any lecture hall. Design a fast greedy algorithm to determine the minimal number of lecture halls required to ensure all activities can happen. Algorithm should also determine activity schedule taking place in each lecture hall used. 
      - The algorithm implemented [🔗 here](https://github.com/gboduljak/clrs-implementations/blob/master/advanced-design-and-analysis-techniques/greedy/interval-graph-coloring/interval-graph-scheduler.c) has O(nlogn) time complexity. All data structures used (min priority queue, doubly linked list) are implemented in the corresponding folders in this repository.
    - Huffman codes [🔗](https://github.com/gboduljak/clrs-implementations/blob/master/advanced-design-and-analysis-techniques/greedy/huffman-codes/huffman.c)
      - A small program to print the generated prefix code [🔗](https://github.com/gboduljak/clrs-implementations/blob/master/advanced-design-and-analysis-techniques/greedy/huffman-codes/huffman-program.c)

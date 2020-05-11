# CLRS Implementations

This is a repository of pseudocode discussed in the main text of a classic - Introduction to Algorithms, known as CLRS.
All implementations are written in C.

The folder structure resembles the book structure. Usually, implementations come with small auxiliary programs and simple test inputs.
For example, along with [heap implementation](https://github.com/gboduljak/clrs-implementations/blob/master/data-structures/heaps/heap.c) there is a small [heap program](https://github.com/gboduljak/clrs-implementations/blob/master/data-structures/heaps/heap-program.c) used to demonstrate heap operations.

Also, although the pseudocode in the book may not have the best variable naming, I have decided to respect it wherever it did not harm readability too much.

Here is a summary of pseudocode implemented so far:

- **Foundations** (Chapters 2,3,4) [🔗](https://github.com/gboduljak/clrs-implementations/tree/master/foundations)
  - InsertionSort
  - MergeSort
  - Maximum Subarray (Divide and Conquer, BruteForce)
- **Sorting and Order Statistics** (Chapters 6,7,8)
  - Heap with all discussed operations [🔗](https://github.com/gboduljak/clrs-implementations/blob/master/data-structures/heaps/heap.c)
  - Heapsort [🔗](https://github.com/gboduljak/clrs-implementations/blob/master/data-structures/heaps/heap.c)

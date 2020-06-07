## 👨‍💻 CLRS Implementations

This is a repository of pseudocode implementations discussed in the main text of a classic - 📖 Introduction to Algorithms, known as CLRS.
All implementations are written in C.

The folder structure resembles the book structure. Usually, implementations come with small auxiliary programs and simple test inputs.
For example, along with [heap implementation](https://github.com/gboduljak/clrs-implementations/blob/master/data-structures/heaps/max-heap.c) there is a small [heap program](https://github.com/gboduljak/clrs-implementations/blob/master/data-structures/heaps/max-heap-program.c) used to demonstrate heap operations.

Also, although the pseudocode in the book may not have the best variable naming, I have decided to respect it for the sake of consistency.

Here is a table of contents of pseudocode implemented so far:

### Foundations (Chapters 2, 3, 4) [🔗](https://github.com/gboduljak/clrs-implementations/tree/master/foundations)

- InsertionSort
- MergeSort
- Maximum Subarray (Divide and Conquer, BruteForce)

### Sorting and Order Statistics (Chapters 6, 7, 8, 9)

- **Max Heap** [🔗](https://github.com/gboduljak/clrs-implementations/blob/master/data-structures/heaps/max-heap.c)
- **HeapSort** [🔗](https://github.com/gboduljak/clrs-implementations/blob/master/data-structures/heaps/max-heap.c)
- **Max Priority Queue** [🔗](https://github.com/gboduljak/clrs-implementations/blob/master/data-structures/heaps/max-priority-queue.c)
- **Min Priority Queue** [🔗](https://github.com/gboduljak/clrs-implementations/blob/master/data-structures/heaps/min-priority-queue.c)
  - Implemented as Max Priority Queue with inverted keys
- QuickSort (non-randomised) [🔗](https://github.com/gboduljak/clrs-implementations/blob/master/sorting/quick-sort/quicksort.c)
- QuickSort (randomised) [🔗](https://github.com/gboduljak/clrs-implementations/blob/master/sorting/quick-sort/randomised-quicksort.c)
- CountingSort [🔗](https://github.com/gboduljak/clrs-implementations/blob/master/sorting/counting-sort/counting-sort.c)
- RadixSort [🔗](https://github.com/gboduljak/clrs-implementations/blob/master/sorting/radix-sort/radix-sort.c)
- BucketSort [🔗](https://github.com/gboduljak/clrs-implementations/blob/master/sorting/bucket-sort/bucket-sort.c)
- RandomisedSelect aka QuickSelect [🔗](https://github.com/gboduljak/clrs-implementations/blob/master/sorting/quick-sort/randomised-select.c)

### Data Structures (Chapters 10, 11, 12, 13)

- **Stack**
  - (array-based) [🔗](https://github.com/gboduljak/clrs-implementations/blob/master/data-structures/stack/stack.c)
  - (doubly-linked-list-based) [🔗](https://github.com/gboduljak/clrs-implementations/blob/master/data-structures/linked-list/stack.c)
- **Queue**
  - (wraparound array-based) [🔗](https://github.com/gboduljak/clrs-implementations/blob/master/data-structures/queue/queue.c)
  - (doubly-linked-list-based) [🔗](https://github.com/gboduljak/clrs-implementations/blob/master/data-structures/linked-list/queue.c)
- **Linked-List** (doubly-linked, circular) [🔗](https://github.com/gboduljak/clrs-implementations/blob/master/data-structures/linked-list/linked-list.c)
- **Hash Table**
  - (chaining) [🔗](https://github.com/gboduljak/clrs-implementations/blob/master/data-structures/hash-tables/chaining/hash-table.c)
  - (open-addressing with double-hashing) [🔗](https://github.com/gboduljak/clrs-implementations/blob/master/data-structures/hash-tables/open-addressing/hash-table.c)
- **Binary Search Tree** [🔗](https://github.com/gboduljak/clrs-implementations/blob/master/data-structures/binary-search-trees/binary-search-tree.c)
  - All discussed operations
- **Red Black Tree** [🔗](https://github.com/gboduljak/clrs-implementations/blob/master/data-structures/red-black-trees/red-black-tree.c)
  - Insertion
  - Deletion
- **AVL Tree** [🔗](https://github.com/gboduljak/clrs-implementations/blob/master/data-structures/avl-trees/avl-tree.c)
  - AVL Sort
  - All discussed BST operations, along with AVL Insert and Delete

### Advanced Design and Analysis Techniques  (Chapters 15, 16)

#### Dynamic Programming (Chapter 15)

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
 - coin changing [🔗](https://github.com/gboduljak/clrs-implementations/blob/master/advanced-design-and-analysis-techniques/dynamic-programming/coin-changing/coin-changing.c)
   - classical dynamic programming problem, presented as exercise 16.1.d)

#### Greedy (Chapter 16)

- activity scheduling [🔗](https://github.com/gboduljak/clrs-implementations/blob/master/advanced-design-and-analysis-techniques/greedy/activity-scheduling/activity-selector.c)
- interval graph coloring(scheduling) - exercise 16.1.4 
  - We are given **n** activities to be held in some lecture halls. For each activity we know its starting time, finishing time and id. Any activity can take place in any lecture hall. Design a fast greedy algorithm to determine the minimal number of lecture halls required to ensure all activities can happen. Algorithm should also determine activity schedule taking place in each lecture hall used. 
  - The algorithm implemented [🔗 here](https://github.com/gboduljak/clrs-implementations/blob/master/advanced-design-and-analysis-techniques/greedy/interval-graph-coloring/interval-graph-scheduler.c) has O(nlogn) time complexity. All data structures used (min priority queue, doubly linked list) are implemented in the corresponding folders in this repository.
- Huffman codes [🔗](https://github.com/gboduljak/clrs-implementations/blob/master/advanced-design-and-analysis-techniques/greedy/huffman-codes/huffman.c)
  - A small program to print a generated prefix code [🔗](https://github.com/gboduljak/clrs-implementations/blob/master/advanced-design-and-analysis-techniques/greedy/huffman-codes/huffman-program.c)

### Graph Algorithms  (Chapters 22, 23, 24, 25)

#### Elementary (Chapter 22)

- **BFS** [🔗](https://github.com/gboduljak/clrs-implementations/blob/master/graph-algorithms/elementary/bfs/bfs.c)
  - performs unweighted shortest path computation
- **DFS** [🔗](https://github.com/gboduljak/clrs-implementations/blob/master/graph-algorithms/elementary/dfs/dfs.c)
  - performs vertex timestamping and edge classification
- **Topological Sorting**
  - classical dfs-based implementation [🔗](https://github.com/gboduljak/clrs-implementations/blob/master/graph-algorithms/elementary/topological-sort/dfs/topological-sort.c)
  - **Kahn's algorithm** implementation [🔗](https://github.com/gboduljak/clrs-implementations/blob/master/graph-algorithms/elementary/topological-sort/kahn-algorithm/kahn.c)
  - both implementations come with a simple program in the same directory which performs topological sort of a textbook 'clothing' directed acyclic graph
- **Strongly connected components** of a directed graph
  - **Kosaraju**'s 'two pass' algorithm [🔗](https://github.com/gboduljak/clrs-implementations/blob/master/graph-algorithms/elementary/strongly-connected-components/kosaraju/kosaraju.c)
    - implemented with the aid of dfs-based topological sort, also implemented above
- Biconnected components of an undirected graph
  - **Hopcroft-Tarjan**'s algorithm for detecting articulation points and bridges [🔗](https://github.com/gboduljak/clrs-implementations/blob/master/graph-algorithms/elementary/biconnected-components/hopcroft-tarjan/hopcroft_tarjan.c)
    - Detects bridges
    - Detects articulation points
#### Minimum Spanning Tree (Chapter 23)
  - **Prim's algorithm** [🔗](https://github.com/gboduljak/clrs-implementations/blob/master/graph-algorithms/minimum-spanning-trees/prim/prim.c)
    - computes the cost and the tree edges set
  - **Kruskal's algorithm** [🔗](https://github.com/gboduljak/clrs-implementations/blob/master/graph-algorithms/minimum-spanning-trees/kruskal/kruskal.c)
    - computes the cost and the tree edges set
  

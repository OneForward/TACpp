
[排序Cpp代码](../codes/sort/sort.cpp)

## 插入排序

```rust
i∈[1, N)                       //循环N-1遍
    x = A[i]
    j∈[i-1, 0] and A[j] > x    //对于比 x 大的数字全部后移一个单位
        A[j+1] = A[j]
    A[j+1] = x;                 //插入x
```


## 冒泡排序

```rust
 i∈[0, N-1)               //循环N-1遍
   j∈[0, N-1-i)           //每遍循环要处理的无序部分
     swap(j, j+1)          //两两排序（升序/降序）
```


## 选择排序

```rust
i∈[0, N-1)     // 循环N-1遍
    min = i
    j∈[i+1, N) // 找到后续的最小值
        if A[j] < A[min]: min = j 
    swap(A[i], A[min])
```


## Shell 排序

```rust
gaps = [701, 301, 132, 57, 23, 10, 4, 1]

for gap in gaps
    for i∈[gap, N)                       //循环N-1遍
        x = A[i]
        j∈[i-gap, -gap, 0] and A[j] > x    //对于比 x 大的数字全部后移一个单位
            A[j+gap] = A[j]
        A[j+gap] = x;                 //插入x
```
 

## 笔记

<!-- | Block sort                | n                        | $n \log n$ | $n \log n$           | 1                       | Yes    | Insertion & Merging      | Combine a block-based {\displaystyle O(n)}# in-place merge algorithm[9] with a bottom-up merge sort.                                                  | -->
<!-- | Quadsort                  | n                        | $n \log n$ | $n \log n$           | n                       | Yes    | Merging                  | Uses a 4-input sorting network.[10]                                                                                                                   | -->
<!-- | Timsort                   | n                        | $n \log n$ | $n \log n$           | n                       | Yes    | Insertion & Merging      | Makes n comparisons when the data is already sorted or reverse sorted.                                                                                | -->
<!-- | Cubesort                  | n                        | $n \log n$ | $n \log n$           | n                       | Yes    | Insertion                | Makes n comparisons when the data is already sorted or reverse sorted.                                                                                | -->
<!-- | Tree sort                 | $n \log n$ | $n \log n$ | $n \log n$(balanced) | n                       | Yes    | Insertion                | When using a self-balancing binary search tree.                                                                                                       |
| Cycle sort                | $n^2$   | $n^2$   | $n^2$             | 1                       | No     | Selection                | In-place with theoretically optimal number of writes.                                                                                                 |
| Library sort              | $n \log n$ | $n \log n$ | $n^2$             | n                       | No     | Insertion                | Similar to a gapped insertion sort. It requires randomly permuting the input to warrant with-high-probability time bounds, which makes it not stable. |
| Patience sorting          | n                        | $n \log n$ | $n \log n$           | n                       | No     | Insertion & Selection    | Finds all the longest increasing subsequences in O(n log n).                                                                                          |
| Smoothsort                | n                        | $n \log n$ | $n \log n$           | 1                       | No     | Selection                | An adaptive variant of heapsort based upon the Leonardo sequence rather than a traditional binary heap.                                               |
| Strand sort               | n                        | $n^2$   | $n^2$             | n                       | Yes    | Selection                |                                                                                                                                                       |
| Tournament sort           | $n \log n$ | $n \log n$ | $n \log n$           | n[12]                   | No     | Selection                | Variation of Heap Sort.                                                                                                                               |
| Cocktail shaker sort      | n                        | $n^2$   | $n^2$             | 1                       | Yes    | Exchanging               | A variant of Bubblesort which deals well with small values at end of list                                                                             |
| Comb sort                 | $n \log n$ | $n^2$   | $n^2$             | 1                       | No     | Exchanging               | Faster than bubble sort on average.                                                                                                                   |
| Gnome sort                | n                        | $n^2$   | $n^2$             | 1                       | Yes    | Exchanging               | Tiny code size.                                                                                                                                       |
| UnShuffle Sort[13]        | n                        | kn                       | kn                                 | n                       | No     | Distribution and Merge   | No exchanges are performed. The parameter k is proportional to the entropy in the input. k = 1 for ordered or reverse ordered input.                  |
| Franceschini's method[14] | n                        | $n \log n$ | $n \log n$           | 1                       | Yes    |             ?            | Performs O(n) data moves.                                                                                                                             |
| Odd–even sort             | n                        | $n^2$   | $n^2$             | 1                       | Yes    | Exchanging               | Can be run on parallel processors easily.                                                                                                             | -->



|      Name      |    Best    |   Average  |    Worst   |  Memory  | Stable |    Method    | Other notes                                                                      |   
|:--------------:|:----------:|:----------:|:----------:|:--------:|:------:|:------------:|----------------------------------------------------------------------------------|   
|    Quicksort   | $n \log n$ | $n \log n$ |    $n^2$   | $\log n$ |   No   | Partitioning | Quicksort is usually done in-place with O(log n) stack space.                 |   
|   Merge sort   | $n \log n$ | $n \log n$ | $n \log n$ |     n    |   Yes  |    Merging   | Highly parallelizable (up to O(log n) using the Three Hungarians' Algorithm). |   
|    Heapsort    | $n \log n$ | $n \log n$ | $n \log n$ |     1    |   No   |   Selection  |                                                                                  |   
| Insertion sort |      n     |    $n^2$   |    $n^2$   |     1    |   Yes  |   Insertion  | O(n + d), in the worst case over sequences that have d inversions.               |   
| Selection sort |    $n^2$   |    $n^2$   |    $n^2$   |     1    |   No   |   Selection  | Stable with {\displaystyle O(n)}# extra space or when using linked lists.    |   
|    Shellsort   | $n \log n$ |  $n^{4/3}$ |  $n^{3/2}$ |     1    |   No   |   Insertion  | Small code size.                                                                 |   
|   Bubble sort  |      n     |    $n^2$   |    $n^2$   |     1    |   Yes  |  Exchanging  | Tiny code size.                                                                  |   
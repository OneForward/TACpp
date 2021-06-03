
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


[TOC]

---

### 任务描述



数学上，一个 $$m \times n$$ 的矩阵是一个由 $$m$$ 行（row）$$n$$ 列（column）元素排列成的矩形阵列。矩阵里的元素可以是数字、符号或数学式。以下是一个由6个数字元素构成的2行3列的矩阵：

$$\begin{pmatrix}1 & 9 & -13 \\\\ 20 & 5 & -6 \end{pmatrix}$$

大小相同（行数列数都相同）的矩阵之间可以相互加减，具体是对每个位置上的元素做加减法。

矩阵的乘法则较为复杂。两个矩阵可以相乘，当且仅当第一个矩阵的列数等于第二个矩阵的行数。矩阵的乘法满足结合律和分配律，但不满足交换律。

两个矩阵的乘法仅当第一个矩阵$$\mathbf{A}$$的列数(column)和另一个矩阵$$\mathbf {B}$$ 的行数(row)相等时才能定义。如$$\mathbf{A}$$是$$m\times n$$矩阵和 $$\mathbf {B}$$ 是 $$n \times p$$ 矩阵，它们的乘积$$\mathbf{AB}$$是一个$$m\times p$$矩阵，它的一个元素

$$AB_{i,j}= A_{i,1}B_{1,j} + A_{i,2}B_{2,j} + \cdots + A_{i,n}B_{n,j} = \sum_{r=1}^n A_{i,r}B_{r,j}$$

其中$$1\leq i\leq m,\ 1\leq j\leq p'$$、。

例如
$$\begin{bmatrix} 1 & 0 & 2 \\\\ -1 & 3 & 1 \\\\  \end{bmatrix} \times \begin{bmatrix} 3 & 1 \\\\  2 & 1 \\\\  1 & 0 \end{bmatrix} = \begin{bmatrix} (1 \times 3  +  0 \times 2  +  2 \times 1) & (1 \times 1   +   0 \times 1   +   2 \times 0) \\\\ (-1 \times 3  +  3 \times 2  +  1 \times 1) & (-1 \times 1   +   3 \times 1   +   1 \times 0) \\\\  \end{bmatrix} = \begin{bmatrix} 5 & 1 \\\\ 4 & 2 \\\\ \end{bmatrix}$$

现在请你设计一个 $$2 \times 2$$ 的矩阵结构体，然后计算一个矩阵 $$A$$ 的 $$n$$ 次幂。为了避免整型溢出，请输出矩阵中每个元素模 $$10^9+7$$ 后的结果。



### 测试说明

输入描述：一个整数 $$n$$ 代表幂次；四个整型 $$a, b, c ,d$$ ，分别代表矩阵 $$A$$ 的四个元素。
$$A = \begin{pmatrix}a & b \\\\ c & d \end{pmatrix}$$

输出描述： $$A^n$$ 中每个元素模$$10^9+7$$ 后的结果。

样例1：

```cpp
100 
1 0 
0 1
```

样例输出1：

```cpp
1 0 
0 1
```

解释1：

$$\begin{pmatrix}1 & 0 \\\\ 0 & 1 \end{pmatrix}^{100} = \begin{pmatrix}1 & 0 \\\\ 0 & 1 \end{pmatrix}$$

样例输入2：

```cpp
3 
1 2 
3 4
```

样例输出2：

```cpp
37    54
81   118
```

解释1：

$$\begin{pmatrix}1 & 2 \\\\ 3 & 4 \end{pmatrix}^{3} = \begin{pmatrix}37 & 54 \\\\ 81 & 118 \end{pmatrix}$$

#### 提示

注意$$0\le n \le 10^{9}$$，直接使用循环乘法可能会超时，请观察如下整数的快速幂算法，仿写矩阵的快速幂算法。算法复杂度 $$O(\log n)$$

```cpp
int fpower(int x, int n) {
    // 计算 x^n, 复杂度 O(log n)
    int ans = 1;
    while (n) {
        if (n % 2) ans *= x;
        x *= x;
        n /= 2;
    }
    return ans;
}
```

---
开始你的任务吧，祝你成功！



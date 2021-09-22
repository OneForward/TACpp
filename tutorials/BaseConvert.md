### 二进制转化完备性的问题
> 10进制小数不一定能转化成二进制小数，是否与10的质因数有2和5，而2质因数只有2有关？
>
> 是不是只有质因数包含另一进制所有质因数的进制才能保证将另一进制的小数精确转化？

回答：首先从实数完备性的角度，指定规则后，**实数与十进制的小数是一一对应的**。进制只是实数的一种表征方法，因此，十进制与二进制的数也是一一对应的。**十进制的小数总能唯一地、精确地转化为二进制的小数。**

学生想表达的应该是：**十进制的小数，未必能够精确地转化为<ins>有限位</ins>的二进制的小数。**

这个表述是正确的。

以下仅讨论区间$(0, 1)$上有限位的十进制小数同有限位二进制小数的转化问题。

给定一个十进制数 $A = \overline{ 0.a_1 a_2 \ldots a_n}$ 与一个二进制数 $B = \overline{ 0.b_1 b_2 \ldots b_m}$，令 $A = B$，则有

$$
\begin{aligned}
&\frac{a_1}{10^1} + \frac{a_2}{10^2} + \cdots + \frac{a_n}{10^n} 
=
\frac{b_1}{2^1} + \frac{b_2}{2^2} + \cdots + \frac{b_m}{2^m} \\ 
\implies & 
2^m \left(\frac{a_1}{10^1} + \frac{a_2}{10^2} + \cdots + \frac{a_n}{10^n} \right)
= b_1 2^{m-1} + \cdots + b_m \in \mathbf{Z} \\ 
\implies & 2^m \left({a_1}{10^{n-1}} + {a_2}{10^{n-2}} + \cdots + {a_n} \right) / 10^n \in \mathbf{Z}
\end{aligned}
$$

我们记 $\overline{A} = A \cdot 10 ^ n =  {a_1}{10^{n-1}} + {a_2}{10^{n-2}} + \cdots + {a_n} \in [1, 10^n-1]$。则原问题变为是否存在一个整数 $m$，使得 $2^m \overline{A} / 10^n \in \mathbf{Z}$。

即使 $m$ 足够大，也必须有 $\overline{A} / 5 ^ n \in \mathbf{Z}$ 才能使条件成立。因此存在大量的 十进制 $A$，无法转化为有限位的二进制小数。

对于第二部分命题：**一个有限位 $p$ 进制的数能精确转化为 有限位的 $q$ 进制数，充要条件是 $q$ 包含 $p$ 的所有质因数。**


这也是正确的。

重写一遍上面的证明。给定一个$p$进制数 $A = \overline{ 0.a_1 a_2 \ldots a_n}$ 与一个$q$进制数 $B = \overline{ 0.b_1 b_2 \ldots b_m}$，令 $A = B$，则有

$$
\begin{aligned}
&\frac{a_1}{p^1} + \frac{a_2}{p^2} + \cdots + \frac{a_n}{p^n} 
=
\frac{b_1}{q^1} + \frac{b_2}{q^2} + \cdots + \frac{b_m}{q^m} \\ 
\implies & 
q^m \left(\frac{a_1}{p^1} + \frac{a_2}{p^2} + \cdots + \frac{a_n}{p^n} \right)
= b_1 q^{m-1} + \cdots + b_m \in \mathbf{Z} \\ 
\implies & q^m \left({a_1}{p^{n-1}} + {a_2}{p^{n-2}} + \cdots + {a_n} \right) / p^n \in \mathbf{Z} \\
\implies & q^m \overline{A} / p^n \in \mathbf{Z} \\
\end{aligned}
$$

显然，由于 $A$ 的任意性，只有当 $q$ 包含 $p$ 的所有质因数时，上述条件才能成立。

# [C++编程、问题与细节【不断更新】](https://github.com/OneForward/TACpp/blob/master/tutorials/Cpp.md)



- [C++编程、问题与细节【不断更新】](#c编程问题与细节不断更新)
  - [入门时问的问题](#入门时问的问题)
    - [1. `int` 和 `short` 都是4字节, 面对一个4字节是否有一个机制能区分它是什么类型（比如存在不同的地方）？](#1-int-和-short-都是4字节-面对一个4字节是否有一个机制能区分它是什么类型比如存在不同的地方)
    - [2. 为什么不同计算机能运行同一个C++程序，而不能运行同一个汇编程序?](#2-为什么不同计算机能运行同一个c程序而不能运行同一个汇编程序)
    - [3. `main` 函数是啥？其参数是干啥的？](#3-main-函数是啥其参数是干啥的)
    - [4. 如何计算立方根？](#4-如何计算立方根)
    - [5. `*` 优先级高于 `&`](#5--优先级高于-)
    - [6. 浮点数精度误差带来的错误](#6-浮点数精度误差带来的错误)
      - [6.1 例子： 整型除法与浮点数除法： `4 / 3 * 1.` 与 `4 * 1. / 3`](#61-例子-整型除法与浮点数除法-4--3--1-与-4--1--3)
      - [6.2 例子： `0.1 + 0.2` 与 `int((3 * 0.6 - 1) * 10)`](#62-例子-01--02-与-int3--06---1--10)
    - [7. 中文全角符号带来的编码问题](#7-中文全角符号带来的编码问题)
    - [8. `namespace` 的意义](#8-namespace-的意义)
  - [常见问题汇总(2020-11-15)](#常见问题汇总2020-11-15)
    - [OJ 评测的文本重定向](#oj-评测的文本重定向)
    - [输出奇怪字符, 或者输出的字符串末尾带有奇怪字符](#输出奇怪字符-或者输出的字符串末尾带有奇怪字符)
    - [指针问题](#指针问题)
    - [未初始化的变量](#未初始化的变量)
  - [常见问题汇总(2020-11-14)](#常见问题汇总2020-11-14)
    - [1. 为何我的代码在Codeblocks（本地）上能运行/能出正确结果，在Educoder上就不行呢？](#1-为何我的代码在codeblocks本地上能运行能出正确结果在educoder上就不行呢)
    - [2. 为何我的代码出现了死循环？](#2-为何我的代码出现了死循环)
    - [3. 为什么我的代码有小部分测例不通过？](#3-为什么我的代码有小部分测例不通过)
    - [4. 关于调试](#4-关于调试)
    - [5. 其他](#5-其他)
  - [常见问题汇总(2020-06)](#常见问题汇总2020-06)
    - [引入头文件、声明、赋值相关问题](#引入头文件声明赋值相关问题)
    - [`cin` 相关的问题](#cin-相关的问题)
    - [函数的参数、返回值与类型签名](#函数的参数返回值与类型签名)
  - [常见问题汇总(2021-04-18)](#常见问题汇总2021-04-18)
    - [什么时候需要显示地调用析构函数?](#什么时候需要显示地调用析构函数)
  - [多文件的经典问题](#多文件的经典问题)
      - [1. 引入头文件忽略了 使用 `std` 命名空间，例如](#1-引入头文件忽略了-使用-std-命名空间例如)
      - [2. 头文件里面声明了某些函数，但是没有在相应的.cpp文件里实现这些函数，会提示 `undefined reference`](#2-头文件里面声明了某些函数但是没有在相应的cpp文件里实现这些函数会提示-undefined-reference)
    - [模板类、抽象基类、内嵌类的相关问题](#模板类抽象基类内嵌类的相关问题)
  - [⭐ 指针，对象的生存期与内存管理](#-指针对象的生存期与内存管理)
  - [常见问题汇总(2020-11-26)](#常见问题汇总2020-11-26)
    - [未定义行为(Undefined Behavior, UB)](#未定义行为undefined-behavior-ub)
  - [C++ 中的一些内置函数的用法](#c-中的一些内置函数的用法)
  - [常见问题汇总(2020-11-18)](#常见问题汇总2020-11-18)
    - [1. 运算符的优先级带来的问题](#1-运算符的优先级带来的问题)
    - [2. 指针未指向合法内存位置就访问](#2-指针未指向合法内存位置就访问)
    - [3. 指针回收相关](#3-指针回收相关)
    - [4. const pointer, pointer to constant](#4-const-pointer-pointer-to-constant)
    - [5. 行尾反斜杠](#5-行尾反斜杠)
  - [Something about C++ (2020-11-14)](#something-about-c-2020-11-14)
  - [⭐C++ 关于获取字符(串)常见的一些问题](#c-关于获取字符串常见的一些问题)
    - [0. Summary](#0-summary)
    - [1. 编程遇到bug，常思考](#1-编程遇到bug常思考)
    - [2. 初始化数组全部为默认值的方法](#2-初始化数组全部为默认值的方法)
    - [3. 输入一个字符。](#3-输入一个字符)
    - [4. 输入跳过空白的方法](#4-输入跳过空白的方法)
    - [5. 读入一行不超过80字符的字符串](#5-读入一行不超过80字符的字符串)
    - [6. 读取到终止（即文本的EOF或者命令行的以 Ctrl Z 结束）](#6-读取到终止即文本的eof或者命令行的以-ctrl-z-结束)
    - [7. 一个经典的错误](#7-一个经典的错误)
    - [8. 另一个经典的错误](#8-另一个经典的错误)
  - [C风格空终止字符串的一些常用内置函数](#c风格空终止字符串的一些常用内置函数)
    - [字符](#字符)
    - [空终止字节字符串](#空终止字节字符串)


## 入门时问的问题
### 1. `int` 和 `short` 都是4字节, 面对一个4字节是否有一个机制能区分它是什么类型（比如存在不同的地方）？

  事实是，类型系统其实是为编译器服务的，用于类型推导、类型检查、组合类型、继承、派生等等，用于检查代码正确性、简化代码。而编译器做好这些类型检查的工作后，转到机器语言时，它们都脱掉了类型这个帽子，而只是单纯的寄存器变量罢了。因此程序在 运行 期间 ，没有 类型 这个约束。在 CPU 看来，`int` 变量只是存储在寄存器上的4字节的值。

  对于机器来说，它只知道命令和对象，并不知道4字节对象是`float`还是`int`。但是指令是有针对性的。譬如整型加法是`ADD`，浮点加法是`ADDSD`之类的。因此，编译器只需要将变量要执行的运算翻译成对应于其类型的机器指令，而对于机器而言，无需再为“类型”去额外存储信息了。

### 2. 为什么不同计算机能运行同一个C++程序，而不能运行同一个汇编程序?

  汇编语言使用的指令往往是和机器的硬件的体系结构有关，譬如x64和arm平台的机器指令都是不同的。具体细节可以等学了嵌入式这门课就知道了。

### 3. `main` 函数是啥？其参数是干啥的？

程序应当含有一个名为 main 的全局函数，它被指定为程序的启动点。它应当有下列形式之一：


```cpp
int main () { body }	(1)	
int main (int argc, char *argv[]) { body }	(2)	

argc	-	非负数，表示从程序运行的环境传递给程序的实参个数。
argv	-	指针，指向包含 argc + 1 个指针的数组的首元素。数组末元素为空指针，若其前面有任何元素，则它们指向空终止多字节字符串，表示从执行环境传递给程序的若干参数。若 argv[0] 不是空指针，或等价地 argc > 0 ，则它指向表示用于调用程序的名称的字符串，或空字符串。
body	-	main 函数的函数体
```


因此，main 函数的参数可以用于为编译后的程序传递命令行参数。


### 4. 如何计算立方根？

编译开启 -std=c++11 或者更新的标准之后，可以使用 `cbrt` 函数

否则，使用传统的 `pow`  函数，但要注意符号问题。

其签名分别为 

```cpp
float cbrt(float arg); // cbrt(x)  x 可以为任意实数
float pow ( float base, float exp ); // pow(x, 1.0/3) 注意 x 需非负
```

### 5. `*` 优先级高于 `&`

### 6. 浮点数精度误差带来的错误

#### 6.1 例子： 整型除法与浮点数除法： `4 / 3 * 1.` 与 `4 * 1. / 3`

```cpp
4 / 3 * 1. = 1. 

4 * 1. / 3 = 1.33
```

#### 6.2 例子： `0.1 + 0.2` 与 `int((3 * 0.6 - 1) * 10)`

![](imgs/2021-09-23-14-26-27.png)

### 7. 中文全角符号带来的编码问题

同学们可能经常会不小心将英文的半角分号 `;` 输入成中文的全角分号 `；`, 归纳如下
- 英文的半角分号 `;` 输入成中文的全角分号 `；`
- 英文的半角括号 `()[]` 输入成中文的全角括号 `（）【】`
- 英文的半角引号 `""` 输入成中文的全角引号 `“”`


这时候的报错通常会提示 identifier 不存在，或者有如下类似提示

```
error: stray '\357' in program
```




![](imgs/2021-09-16-21-09-24.png)



### 8. `namespace` 的意义

- `namespace` 是语法层面的概念，没有内存的开辟这一操作
- `namespace` 的意义仅仅在于：编译器在编译代码的时候，给不同 namespace 下的代码提供一个独立的编译语境（context），避免变量名字的冲突



## 常见问题汇总(2020-11-15)

### OJ 评测的文本重定向 

```cpp
// #include <cstdio>
freopen("in.txt", "r", stdin);
```


### 输出奇怪字符, 或者输出的字符串末尾带有奇怪字符

字符串的末尾缺少 `\0` 控制。解决方法，增加一个字符结束的判断（要么使用长度，要么结合实际问题解决），或者字符数组初始化时先全部赋值为 0。

### 指针问题

- 变量或者对象的值没有初始化，或者类内某些成员没有初始化。
- 对象delete后没有将对应的指针赋值为`nullptr`或`NULL`，造成后续的判空问题。
- 定义数组时，数组大小使用变量。
- 数组没有初始化却被访问。（可能引发**SIGSEGV**内存异常的中断）
- 数组越界访问。（可能引发**SIGSEGV**中断）

```c++
int N; cin >> N; int arr[N];  // 错误，数组大小不应该使用变量。这样的处理方式可能会有内存问题。
```

更多问题请参考[关于指针的内存管理的问题](#指针对象的生存期与内存管理)

### 未初始化的变量 

简要总结就是local对象（如函数中，特别的，main 函数中的）、堆上的对象的值是 undefined 。

而global作用域的对象、static对象、带有默认构造的对象会被赋予默认值(default contructor)。

一个好习惯是变量声明的时候顺势也初始化赋值。



## 常见问题汇总(2020-11-14)

### 1. 为何我的代码在Codeblocks（本地）上能运行/能出正确结果，在Educoder上就不行呢？


- 终止判断原因。Educoder的多行测例的最后一行往往是不包含换行符（`\n`）的；而在Codeblocks下同学们实际上会手动地加入一个换行符。关于如何进行合理的终止判断，请参见[C++关于获取字符串常见的一些问题](#c-关于获取字符串常见的一些问题)
- 数组越界原因。Codeblocks和Educoder对数组的未初始化部分处理是有区别的，如果我们想要访问的数组元素实际超出了预想的范围，则有可能出现奇怪内容，或进而导致程序死循环。另外需要注意的是字符串最后是有`\0`字符的。（可以考虑将数组调大）

### 2. 为何我的代码出现了死循环？


- 请检查你的循环条件逻辑是否正确、实际代码是否符合逻辑？可以通过debug功能查看循环变量和一些中间变量的表现，来判断代码是否按照你的预设思路执行。
- 在多层循环中，请注意检查不同层次的循环变量是否出现了不合理的交互？（譬如内层循环不合理地修改了外层循环变量，或者两层循环使用了同样的循环变量名？）
- 数组越界原因，不再赘述。

### 3. 为什么我的代码有小部分测例不通过？


大体上是因为代码没有考虑到特殊情况。可以从以下几个方面思考检查：
- 极端测例。如果测例条件达到了题目设置条件的上下限，代码是否会有越界等问题？是否因为部分测例过于“简单”而我的代码没有考虑这种情况？
- 多次重复测例。有些测例（譬如在寻找字符串类型题目中）需要我们多次地进行相似的检查判断，这种时候代码中的一些变量是否合理及时地进行了重置？每一次检验后是否会影响后续检验的初始条件或判断条件？

### 4. 关于调试

- 对中间变量进行调试。
- 如果遇到数组问题测试样例不通过，建议将程序过程中的数组按行cout出来，判断和预想的结果是否一致。

### 5. 其他

- 不要着急动手写程序，写程序之前先考虑逻辑是否符合题目要求，有什么难点需要解决，以前是否遇到类似的题目，是否有更好的方法来解决这种问题。




## 常见问题汇总(2020-06)

### 引入头文件、声明、赋值相关问题 

- 引用自己实现的头文件应使用双引号而非尖括号

  ```c++
  #include "my_headers.h" // OK
  ```

- 指针的声明问题。

  ```c++
  Node* p1, p2, p3; // 注意p2, p3类型不是 Node*
  ```

- C++的赋值都是值传递。体会差别：

  ```c++
  struct Node { 
      int data;
  	Node* next;
      Node(int d=0): data(d) {}
  };
  
  Node* head = new Node();
  
  // method 1
  Node* next = head->next; next = new Node(); 
  ```

  与

  ```c++
  // method 2
  head->next = new Node();
  ```

  只有方法2可以正确的构造新节点。

- 无法使用`nullptr`等。

  可以在编译选项中开启`-std=c++11`。

### `cin` 相关的问题 
- `cin.get()`, `cin.getline()` , `cin >>` 问题。

  OJ上一般不推荐使用 `cin.get()` ，理由是get遇到界定符时,停止执行,但并不从流中提取界定符（如换行符）,再次调用会遇到同一个界定符,函数将立即返回,不会提取输入，导致程序运行异常。   

### 函数的参数、返回值与类型签名

- 数组如何作为函数参数。

  数组做参数时会直接被隐式转化为指针。如下声明是等价的

  ```c++
  void f(int []);
  void f(int *);
  ```

  虽然也可以写出数组大小 `void f(int [10]);`，但是不推荐。二维数组有`void f(int [][10])`的写法，亦不推荐。

- 函数默认参数问题。

  C++规定默认参数只能在声明或者定义中出现一次。一般建议将默认参数写在声明中。

  ```c++
  struct Array {
  	Array(int capacity=10);
  };
  
  Array::Array(int capacity=10) {} // 错误
  Array::Array(int capacity) {} // OK
  ```

  

- 函数存在无返回值的可能性。

  忘记写返回，如**赋值运算符重载忘记返回*this**。或者**没有管辖到条件分支的所有情况**。

  ```c++
  int f(int x) {
  	if (x == 0) return 0;
      // warning: control reaches end of non-void function [-Wreturn-type]
  }
  ```

- 前置函数声明，在后面实现函数时，函数签名不匹配。(`const`，`&`修饰符)

  例如

  ```c++
  // 前置的函数声明
  bool search(const int&) const;

  // 后置函数实现
  // void search(const int&) const {...}; 错误，函数签名不匹配
  // bool search(int&) const {...}; 错误，函数签名不匹配
  // bool search(const int) const {...}; 错误，函数签名不匹配
  // bool search(const int&) {...}; 错误，函数签名不匹配
  bool search(const int&) const {...}; // OK
  ```




## 常见问题汇总(2021-04-18)

### 什么时候需要显示地调用析构函数?

绝大多数时候都请不要显示地调用析构函数，可能出现 runtime error (对象内部成员的内存空间被试图重复回收，引起 内存异常的 中断)。


```cpp
struct A
{
    int* data;
    A(): data{new int[100]}{}
    ~A() { delete [] data; }
};

A a;
// a.~A(); // error, a is stack object which will be destroyed implicitly; thus, a.data might be destroyed twice


{
    A* a = new A;
    a->~A(); // ok, the object a points to resides on heap and should be destroyed explicitly
}
```

## 多文件的经典问题

同学们，这里是两个多文件的经典问题

#### 1. 引入头文件忽略了 使用 `std` 命名空间，例如

![](imgs/forget_std.jpg)

这里要么使用 `std::ostream` ，要么引入 `std` 命名空间

#### 2. 头文件里面声明了某些函数，但是没有在相应的.cpp文件里实现这些函数，会提示 `undefined reference`

例如

![undefined_reference](imgs/undefined_ref.jpg)

这里的错误的原因是头文件里面声明了析构函数，但作者忘记了实现它（头文件里面不写明的话编译器则会帮你实现）

> 同时要注意函数声明与定义时的签名是否一致。见 [函数的参数、返回值与类型签名](#函数的参数返回值与类型签名)

> 另一种可能是模板类的实现和声明分开来写，也会出现 `undefined reference`，如下一小节所讲述的。

### 模板类、抽象基类、内嵌类的相关问题

- 一般建议模板类的实现和声明写在同一个文件里，不分开成两个文件写。

 很多同学问过这个问题。例如

```c++
// file Array.h
template<class T> class Array {
	T* data;
	int capacity;
public:
	Array(int capacity=10);
};
```

```c++
// file Array.cpp

#include "Array.h"
template<class T> Array<T>::Array(int capacity) {
	data = new T[capacity];
}
```

```c++
// file main.cpp

#include "Array.h"
int main() {
	Array<int> A; // failed!
}
```

这里错误的原因时编译的时候每个`.cpp`是独立编译然后链接的。头文件不会被编译，只会做预处理，然后附在 `.cpp`编译后的文件中。因此编译 `main.cpp` 的时候只看见头文件，没有看见实现，也就不知道模板实例如何实现。最终导致 `main.exe` 调用时找不到模板实例的实现。有两种解决方法

1. 将Array的实现和声明都写在一个头文件里，这样 `main` 就可以看到模板实现了。

2. 在实现中显示地添加需要的模板实例，例如

   ```c++
   // file Array.cpp
   
   #include "Array.h"
   template<class T> Array<T>::Array(int capacity) {
   	data = new T[capacity];
   }
   
   template class Array<int>; // 显示添加模板实例
   ```

- 继承抽象基类时，没有将该抽象基类所有的纯虚成员重新实现。

  ```c++
  class List {
  public:
      virtual int size() const = 0; // pure virtual function 
      virtual ˜List() {} // destructor 
  };

  class Stack: public List {
  public:
      // 忘记定义和实现 int size() const ...
  };
  ```



- 定义某个继承类时，基类必须已经实现，且继承类应在定义时实现。

  ```c++
  struct List; 
  strcut LinkList: public List {}; // 错误，基类没有实现
  ```

  ```c++
  struct List {}; 
  strcut LinkList: public List; // 错误，继承类没有在定义处实现
  ```

- 访问内嵌类。

  ```c++
  struct List {
      struct Node { };
  };
  
  typename List::Node* pNode = new typename List::Node;
  ```
  
  
  


## ⭐ 指针，对象的生存期与内存管理

- 变量或者对象的值没有初始化，或者类内某些成员没有初始化。
- 对象delete后没有将对应的指针赋值为`nullptr`或`NULL`，造成后续的判空问题。
- 定义数组时，数组大小使用变量。
- 数组没有初始化却被访问。（可能引发**SIGSEGV**内存异常的中断）
- 数组越界访问。（可能引发**SIGSEGV**中断）

```c++
int N; cin >> N; int arr[N];  // 错误，数组大小不应该使用变量。这样的处理方式可能会有内存问题。

class List {
    ...
public:
    ...
    int getMax() const {
        int max; // max 忘记初始化
        for ...
    }
};

int* data = new int[255];
visit(data[0]); // 没有初始化直接访问 data 数据


int* ptr = new int;
delete ptr; // delete后忘记置NULL
if (ptr == nullptr) { // 无法进入该分支
    ...
}
```



- 指针没有`new`就访问。此时指针值是随机值或者`NULL`，访问该位置的内存会引发**SIGSEGV**中断。

- 指针`delete`后再被访问或者再试图`delete`。此时指针值所在的内存位置已经没有对象，任何访问都将引发**SIGSEGV**中断。

  **对象在生存期内，可能被多个指针共享**。假如这些指针都是只读的(read-only)，则一点问题没有。但假若某个指针在某个地方对对象进行了写操作或者删除了对象，新手容易遗忘这件事，然后在别地方使用别的指针操作该对象时出错。

- 指针`new`完再`new`，程序没有记住第一次`new`出来的对象的地址，造成原来的对象悬浮。指针`new`完没有`delete`，这个对象会一直占用内存位置，直到程序结束时由系统回收。

  不过目前而言，这里只会造成内存浪费，对运行不影响。

```c++
int* p; // p points to random position of memory
*p = 1; // trouble


int* p1 = new int{99};
int* p2 = p1; // potential trouble
delete p1; // now p2 doesn’t point to a valid object
p1 = nullptr; // gives a false sense of safety
*p2 = 999; // this may cause trouble


int* p3 = new int{99}; // object1
p3 = new int{99}; // p3 points to object2, and object1 is dangling
```


## 常见问题汇总(2020-11-26)

### 未定义行为(Undefined Behavior, UB)

```cpp
int i = 1;
i = i+++i; // UB, 不同的编译器给出的结果不同
```

请严格避免 UB。


## C++ 中的一些内置函数的用法

[C++ 中的一些内置函数的用法](https://gitee.com/OneForward/TACpp/blob/gitee/tutorials/CppFuncs.md)


## 常见问题汇总(2020-11-18)

### 1. 运算符的优先级带来的问题

例如

```cpp
char ch;
while (ch = cin.get() && ch != '\n'); // 错误写法, 无法终止，且 ch 始终为 1
```

这个写法的结果是永远不会结束，并且所有 ch 的值都是 整型1 ( '\x1' )

原因是实际赋值的过程是 

```cpp
ch = (cin.get() && ch != '\n')
```

注意到 `cin.get()` 永远不会返回 0（即使文本结束也是返回-1），故 `cin.get()` 为真； 
而右侧 ch 的值在这种写法下只能为 0 或 1, 故 `ch != '\n'` 为真。
因此布尔表达式的结果永远是 true，转型赋值给 char 后即为 1。由于 赋值表达式的值是被赋值的结果，此处始终为 1, 故而 while 循环不会结束。

直接修改如下

```cpp
char ch;
while ((ch = cin.get()) && ch != '\n'); // 仍有问题，如果输入没有 换行符则无法结束
```

```cpp
char ch;
while ((ch = cin.get()) && ch != -1); // 仍有问题，可能输入了不需要的换行符 \n
```

正确写法

```cpp
char ch;
while ((cin.get(ch)) && ch != '\n'); // ok
```

### 2. 指针未指向合法内存位置就访问


```cpp
// 错误写法1
int* p; // p points to random position of memory
*p = 1; // trouble
```

```cpp
// 错误写法2
int* p;
p = &1; // compiler error, 取地址运算符只能作用于左值（例如变量）
```

```cpp
// 合理写法
int* p; int x = 1;
p = &x; // ok , p points to x
p = new int{1}; // ok, p points to temprary object on the heap
```


- 案例 1 
  ```cpp
  char* s;
  strcpy(s, "SJTU"); // 错误, s 没有指向合法位置
  ```
- 案例 2

  ```cpp
  // 获取一行字符串
  char* s;
  cin.getline(s, 80); // 错误，s 没有指向合法位置
  ```



### 3. 指针回收相关

```cpp
// 错误写法1
int* p; // p points to random position of memory
delete p; // trouble
```

```cpp
// 错误写法2
int* p; // p points to random position of memory
delete p; // trouble
if (p == nullptr) { // 错误, p的值未必为空
  // ... something ...
} 

int* p; int x = 1;
p = &x;
delete p; // delete 和 new 应当相对应出现, delete stack object is undefined behavior(UB)
cout << x; // trouble
```

```cpp
// 错误写法3
void f() {

    int* p = new int[100]; 
    delete[] p; 

    // ... wait a while ...

    delete[] p; // error, 不能回收一个已经被回收的内存
}
```


```cpp
// 错误写法4
int* p1 = new int { 99 };
int* p2 = p1; // potential trouble


delete p1; // now p2 doesn’t point to a valid object
p1 = nullptr; // gives a false sense of safety


char* p3 = new char { 'x' };

*p2 = 999; // error, 试图访问已被回收的内存

cout << *p3;
```


```cpp
// 错误写法5
// 指针 p 指向某个对象
delete p; // 回收该对象
if (p == nullptr) { // 错误, 指针p的值未必为空
  // ... something ...
} 
```



### 4. const pointer, pointer to constant

* `const char* p`; 叫做 `pointer to const char`, 意思是 p 指向的对象不可变
* `char* const p`; 叫做 `const pointer to char`，意思是 p 不可变，但 p 指向的对象的值可以变( 例如 p 不可以自加，但是 *p 可以改值 )
* `const char * const p`; 叫做 `const pointer to const char` ;  二者都不可变

```cpp
void f1(char *p)
{
    char s[] = "Gorm";
    const char *pc = s;        // pointer to constant
    pc[3] = 'g';               // error : pc points to constant
    pc = p;                    // OK
    char *const cp = s;        // constant pointer
    cp[3] = 'a';               // OK
    cp = p;                    // error : cp is constant
    const char *const cpc = s; // const pointer to const
    cpc[3] = 'a';              // error : cpc points to constant
    cpc = p;                   // error : cpc is constant
}

int count_length(const char *s)
{
    int len = 0;
    while (*s) len++, s++; // ok, 
    return len;
}
```

### 5. 行尾反斜杠

编译器翻译文本时，当反斜杠出现于行尾（其后紧跟换行符）时，会删除该反斜杠和换行符，将两个物理源码行组合成一个逻辑源码行

https://zh.cppreference.com/w/cpp/language/translation_phases

```cpp
// someth comment...\
int x = 0;
cout << x; 
```

编译提示
```cpp
hello.cpp: In function 'int main()':
hello.cpp:8:13: error: 'x' was not declared in this scope
     cout << x;
```

## Something about C++ (2020-11-14)

* 最小的C++实现

* `#include` 宏的本质

* `sizeof` 的使用

* 字符串字面量

* 数组、指针以及作为函数参数、函数返回值

* 变量可以绑定常量吗

* 数组, 对象的花括号初始化

* 逗号, 分号与表达式的值

* 花括号与作用域, 局部变量, 全局变量与静态变量 



## ⭐C++ 关于获取字符(串)常见的一些问题

### 0. Summary

- **注意：很多同学使用循环到 遇到 `'\n'` 终止读入, 虽然本地终端输入字符串总是会在末尾多敲一个换行符（提示 `cin` 开始读入），但 EduCoder 传入的字符串未必需要包含 `'\n'`**
- 因此造成本地与 EduCoder 的程序运行结果不同

```cpp
/* You may always use `cin.getline` for reading string from stdin. */


// Q1: 读入一行字符串
char s[80] {}; // 声明一个字符数组，并且全部填充 '\0' (也就是 0)
cin.getline(s, sizeof s); // 读入一行不超过80字符的字符串
// 默认遇到 EOF、'\n'、超出80字符、异常 等都可以自动停止，
// 并且保证 s 里面的字符串以 '\0' (也就是0) 结尾


// Q2: 输入一个数字和若干行字符串
// 正确写法
int n; 
char lines[10][80]; // 保存不超过10个字符串,每个字符串长度不超过80
cin >> n; cin >> ws; // 添加一个跳过空白的语句
for (int i=0; i < n; ++i) cin.getline(lines[i], 80);
```

### 1. 编程遇到bug，常思考
   - **我的变量都初始化了吗？**
   - **我的数组初始化了吗？**
   - **访问数组时，访问了没有初始化的位置了吗？**
   - **数组访问越界了吗？**

### 2. 初始化数组全部为默认值的方法

```cpp
const int N = 1024;
int arrA[N] = {}; // 默认全部为 0
bool arrB[N] = {}; // 默认全部为 false
char arrC[N] = {}; // 默认全部为 '\0'
// 或者写一个 for 循环赋值，或者使用 memset
// C++11之后上述等号也可以全部删掉，甚至还有
int *pArr = new int[N] {}; // 在堆上构造一个全部为0的动态数组
```

### 3. 输入一个字符。

```cpp
char ch;
cin.get(ch);
// 或者 cin >> ch; // 只能读入非空白字符
```

### 4. 输入跳过空白的方法 
```cpp
// 方法1
cin >> ws;
```

```cpp
// 方法2，不推荐
cin.clear();
cin.ignore(100, '\n'); // 忽略字符流(至多忽略100个字符)，直到遇到换行符，消耗掉换行符并继续
```

### 5. 读入一行不超过80字符的字符串
```cpp
char s[80];
cin.getline(s, sizeof(s)); 
// cin.getline(s, 80); // 等价
// cin.getline(s, 80, '\n'); // 等价
// 虽然此处 cin.getline 全部可以使用 cin.get 替换，但稍有区别，
// cin.get 遇到'\n'终止时不会消耗掉'\n'，下一次读入还是 '\n'
// cin.getline 会消耗掉 '\n'，下一次读入是新字符
// 因此不推荐使用 cin.get
```

### 6. 读取到终止（即文本的EOF或者命令行的以 Ctrl Z 结束）
```cpp
// 方法1
char ch;
while ((ch = cin.get()) != EOF);

// 或者存入数组
char s[80]; int len = 0;
while ((s[len++] = cin.get()) != EOF); // EOF is a c/c++ macro, EOF = -1
```

```cpp
// 方法2
char ch;
while (cin.get(ch));

// 或者存入数组
char s[80]; int len = 0;
while (cin.get(s[len++])); 
```

```cpp
// 方法3
// 注意到
char s[80];
cin.getline(s, 80); // 默认情况下遇到 EOF 也会正常结束

// 因此
// 逐行读入
char lines[10][80]{}; int n = 0; // 这里 n 表示字符串个数
while ( cin.getline(lines[n++], 80) ); // 默认情况下遇到 EOF 也会正常结束
```

```cpp
// 错误的方法 
char s[80]; int len = 0;
while ( !cin.eof() && (s[len++] = cin.get()) != '\n');
// 会在最后错误地多读一位 EOF, 也就是 -1
// almostly never use cin.eof()!
```


### 7. 一个经典的错误 

> 输入一个数字和若干行字符串

要注意数字后面有一个换行符，不加注意可能会影响之后读取字符串（少读一行或者其他问题）
这里的换行符的处理方式很多，我个人喜欢 `cin >> ws;` 跳过空白，或者 `cin.get();` 置位读入换行符也可以

```cpp
// 输入文本
2
string
help
```

```cpp
// 错误写法
int n; 
char lines[10][80]; // 保存不超过10个字符串,每个字符串长度不超过80
cin >> n;
for (int i=0; i < n; ++i) cin.getline(lines[i], 80);
```

这里的错误是将会 `lines[0]`保存的将会是一个空字符串, 因为数字的末尾是一个换行符,第一次输入便暂停了.


```cpp
// 正确写法
int n; 
char lines[10][80]; // 保存不超过10个字符串,每个字符串长度不超过80
cin >> n; cin >> ws; // 添加一个跳过空白的语句
for (int i=0; i < n; ++i) cin.getline(lines[i], 80);
```

### 8. 另一个经典的错误

> 读入一行字符串 

```cpp
// 错误写法1
int i = 0; char s[80];
while ( cin >> s[i] ) i++; // 无法获得空白字符
```

```cpp
// 错误写法2
char ch; 
int i = 0; char s[80];
while ( (ch = cin.get()) != EOF ) s[i++] = ch; // 可能错误读入换行符
```

```cpp
// 错误写法3
int i = 0; char s[80];
while ( (s[i] = cin.get()) != '\n' ) i++; // 假如没有换行符，将不会停止
```

以上代码均有部分问题 

```cpp
// 正确写法1
cin.getline(s, 80);
```

```cpp
// 正确写法2
int i = 0; char s[80];
while ( cin.get(s[i]) && s[i] != '\n' ) ++i; // 小的潜在错误, 缺少80字符判断
```



## C风格空终止字符串的一些常用内置函数

官方介绍见[链接](https://zh.cppreference.com/w/cpp/string/byte)
以下介绍的函数绝大多数情况下，都在引入 `<iostream> <cstdio> <cstring> <cstdlib>` 库后便可以使用

### 字符

| 字符分类 |  |
| :-: | :-- |
| `isalnum` | 检查字符是否为字母或数字 |
| `isalpha` | 检查字符是否为字母 |
| `islower` | 检查字符是否为小写 |
| `isupper` | 检查字符是否为大写字符 |
| `isdigit` | 检查字符是否为数字 |
| `isspace` | 检查字符是否为空白间隔字符 |
| `isblank` | 检查字符是否为空白字符(C++11) |
| `isprint` | 检查字符是否为打印字符 |
| `ispunct` | 检查字符是否为标点符 |
| **字符操作** | |
| `tolower` |  转换字符为小写 |
| `toupper` |  转换字符为大写 |

### 空终止字节字符串

C风格空终止字节字符串（ null-terminated byte string ）是后随拥有零值的字节（空终止字符）的非零字节序列。

<ins> 以下用于空终止字节字符串的函数均要注意传入的字符串必须是**合法的以 `'\0'` 结尾的**字符指针或者字符数组. </ins>

个人在正常书写C++代码的时候很少使用这些函数, 等考试结束之后同学们还是学习使用更加安全与方便的 `string` 类型吧.
 
| 转换为数值格式 | 定义于头文件 `<cstdlib>` |
| :-: | :-- |
| `atof` | 转换字节字符串为浮点值 |
| `atoi` | 转换字节字符串为整数值 |
| **字符串操作** | **定义于头文件 `<cstring>`** |
| `strcpy` | 复制一个字符串给另一个 |
| `strncpy` | 复制来自一个字符串的一定量字符给另一个 |
| `strcat` | 连接两个字符串 |
| `strncat` | 连接两个字符串的一定量字符 |
| **字符串检验** | **定义于头文件 `<cstring>`** |
| `strlen` | 返回给定字符串的长度 |
| `strcmp` | 比较两个字符串 |
| `strncmp` | 比较两个字符串的一定量字符 |
| `strchr` | 寻找字符的首次出现 |
| `strrchr` | 寻找字符的最后出现 |
| `strstr` | 寻找字符子串的首次出现 |




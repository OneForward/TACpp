# [C++ 中的一些内置函数的用法](https://gitee.com/OneForward/TACpp/blob/gitee/tutorials/CppFuncs.md)

- [C++ 中的一些内置函数的用法](#c-中的一些内置函数的用法)
  - [与输入控制相关的函数](#与输入控制相关的函数)
    - [1. `cin.clear()`、`cin.sync()` 用法](#1-cinclearcinsync-用法)
    - [2. `cin.ignore` 用法](#2-cinignore-用法)
    - [3. `getline `用法](#3-getline-用法)
    - [4. `get` 用法](#4-get-用法)


## 与输入控制相关的函数

### 1. `cin.clear()`、`cin.sync()` 用法

* `cin.clear()` 用于 reset failbit，尤其应用在输入流错误的时候重置输入流的状态位（例如向int变量输入一段字母），以便于能继续获取输入（输入流的状态位不是 goodbit 时输入阻塞，无法获取任何输入的） 。

  例如

  ```cpp
  int age; char price[];
  // 输入是 "hello 12 12"
  cin >> age; // 异常
  cin >> price;  // 无法读入，置 ""
  cout << age << " " <<  price; // 输出 0 
  ```

  ```cpp
  int age, price;
  // 输入是 "hello 12 12"
  cin >> age; // 异常

  cin.clear(); // 重置输入流状态位为 goodbit

  cin >> price;  // 读入， "hello"
  cout << age << " " <<  price; // 输出 0 hello
  ```

  一个用途在于输入检查

  ```cpp
  double n;
  while( cout << "Please, enter a number\n"
          && ! (cin >> n) )
  {
      cin.clear();
      string line;
      getline(cin, line);
      cout << "I am sorry, but '" << line << "' is not a number\n";
  }
  cout << "Thank you for entering the number " << n << '\n';
  ```


* `cin.sync()` **不应当使用**，因为不同的编译器有不同的实现，结果是不一样的。一般情况下，这句语句在gcc编译器的结果是 清空输入流的缓冲区，msvc编译器则是什么也不做。（例如 

  ```cpp
  int x, y; 
  cin >> x; cin.sync(); 
  cin >> y; 
  ```

  在 gcc 编译器下只有 x 能被正确赋值，y是0；在msvc编译器下x,y都能正确赋值。

### 2. `cin.ignore` 用法

* `cin.ignore(size_t n, char delim);` : 废弃输入流，直到遇到分隔符 `delim` ，或者达到 `n` 个字符

### 3. `getline `用法

- `cin.getline( char* s, int n, char delim='\n' )` 
  
  获取一行字符串，遇到以下情形输入结束
  - 输入达到 `n` 个字符
  - 遇到分隔符 `delim`， 默认是 `'\n'`
  - 输入流结束（如文本重定向的 EOF）

  这是一个安全好用的函数，能够自动处理各种异常情形。例子
  ```cpp
  char s[80];
  cin.getline(s, 80); // 获取一行字符串
  ```


- `getline( cin, string& s,  char delim='\n' )` 

  类似 `cin.getline` 用法，不同的是赋值的对象是 `string` 类而非字符数组（指针）。

    ```cpp
    string s;
    getline(std::cin, name);// 获取一个字符串，遇到 \n 结束
    ```

### 4. `get` 用法

- `int cin.get();`
  
  读取一个字符，若可用则返回它。否则，返回 EOF = -1

- `cin.get(char& ch);`

  **推荐使用。**
  读取一个字符，而若可用则存储于 ch 。否则，保留 ch 不修改。注意到不会异常读入 EOF ，因此是安全的。见 [读取到终止（即文本的EOF或者命令行的以 Ctrl Z 结束）](https://gitee.com/OneForward/TACpp/blob/gitee/tutorials/Cpp.md#6-读取到终止即文本的eof或者命令行的以-ctrl-z-结束)

- `cin.get( char* s, int n, char delim='\n' );`

  **不推荐使用**。
  获取一行字符串，遇到以下情形输入结束
  - 输入达到 `n` 个字符
  - 遇到分隔符 `delim`， 默认是 `'\n'`
  - 输入流结束（如文本重定向的 EOF）

  <ins>注意遇到分隔符后**分隔符不会被消耗，仍然留在输入流里面**，下一次输入仍是分隔符开始。因此**不推荐使用**。</ins>

关于如何安全地获取一行字符串、多行字符串，见 [C++ 关于获取字符(串)常见的一些问题](https://gitee.com/OneForward/TACpp/blob/gitee/tutorials/Cpp.md#c-关于获取字符串常见的一些问题)。
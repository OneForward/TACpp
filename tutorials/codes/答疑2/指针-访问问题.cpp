#include <iostream>
using namespace std;

int main()
{
// ### 2. 指针未初始化就解引用

// 错误写法1
// int* p; // p points to random position of memory
// *p = 1; // trouble

// 错误写法2
// int* p;
// p = &1; // compiler error, 取地址运算符只能作用于左值（例如变量）

// 合理写法
// int* p; int x = 1;
// p = &x; // ok , p points to x
// p = new int{1}; // ok, p points to temprary object on the heap

// ### 3. 指针指向的对象已被回收

// 错误写法1
// int* p; // p points to random position of memory
// delete p; // trouble

// 错误写法2
// int* p; int x = 1;
// p = &x;
// delete p; // delete 和 new 应当相对应出现, delete stack object is undefined behavior(UB)
// cout << x; // trouble

// 错误写法3
// int* p = new int[100]; 
// delete[] p; 
/*
    ... wait a while ...
*/
// delete[] p; // error, 不能回收一个已经被回收的内存


// 错误写法4
int* p1 = new int { 99 };
int* p2 = p1; // potential trouble


delete p1; // now p2 doesn’t point to a valid object
p1 = nullptr; // gives a false sense of safety

char* p3 = new char { 'x' };

*p2 = 999; // error, 试图访问已被回收的内存

cout << *p3;

}

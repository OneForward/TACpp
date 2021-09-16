[TOC]

---

## 任务描述

本题基于实验指导书p85，实验11。

输入若干个正整数（输入-1作为输入结束标志），要求按照输入顺序的逆序建立一个单链表，并输出。

程序运行示例：
请输入若干个正整数（-1结束）

```
1 4 89 56 -1
```

按照输入顺序逆序输出

```
56 89 4 1
```

## 错误程序
以下代码清单是有错的源程序，请进行改正。

```cpp
#include <iostream>
using namespace std;

struct List
{
    int num;
    List *next;
};

int main()
{
    List *head,*p,*q;
    int num;

    head = NULL;
    cout << "请输入若干个正整数（-1结束）\n";
    cin >> num;
    while(num != -1)
    {
        p = new List;
        p->num = num;
        head = p->next;
        head = p;
        cin >> num;
    }

    cout << "按照输入顺序逆序输出\n";
    for(p = head; p->next != NULL; p = p->next)
    {
        cout << p->num << " ";
    };
    cout << endl;

    for(p = head; p != NULL; p = q)
    {
        q = p->next;
      delete p;
    }

    return 0;
}
```

---
开始你的任务吧，祝你成功！



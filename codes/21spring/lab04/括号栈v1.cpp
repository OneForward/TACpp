/*
sjtu1605

括号栈：提供 全部 O(1) 的 push, pop, top, query(是否为合法括号栈)
*/


#include <iostream>
using namespace std;

const int N = 2e6 + 5;

template<class T> struct Stack
{
    T* data;
    int len;

    Stack(): data{new T[N]}, len{} {}

    void push(T x) { data[len++] = x; }

    void pop() { len--; } 

    T top() const { return data[len-1]; }

    bool empty() const { return len == 0; }

    int size() const { return len; }
};


char left(char ch) {
    switch (ch)
    {
    case ')': return '(';
    case ']': return '[';
    case '}' : return '{';
    }
    return '$';
}

bool isMatch(char lft, char rht) { return lft == left(rht); }

bool isRight(char rht) { return left(rht) != '$'; }



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    Stack<char> S1, S2;

    int n, op; char ch;
    cin >> n;
    while (n--) {
        cin >> op;
        switch (op) {
            case 1: cin >> ch;  // 插入
                    if (S2.size() and isMatch(S2.top(), ch)) S1.push('#'),  S1.push(ch), S2.pop();
                    else  S1.push(ch), S2.push(ch);
                break;
            case 2: if (S1.size()) { // pop
                    ch = S1.top(); S1.pop();
                    if (isRight(ch) and S1.size() and S1.top() == '#') S1.pop(), S2.push(left(ch));
                    else S2.pop();
                }
                break;
            case 3:  if (S1.size()) cout << S1.top()  << '\n'; break;  // top
            case 4:  cout << (S2.empty() ? "YES\n" : "NO\n");  // isValid
        }
    }
    
    return 0;
}

#include <iostream>

using namespace std;

template<class T> struct Stack{
    T* arr;
    int len;
 
    Stack(int size): len(0) { arr = new T[size]; }
    
    bool isempty() const { return len == 0; }
    
    int length() const { return len; }
    T top() const { return arr[len-1]; }
 
    void push_back(int val) {
        arr[len++] = val;
    }
 
    T pop() {
        return arr[--len];
    }
 
    T& operator[](int i) { return arr[i]; }
    T& operator[](int i) const { return arr[i]; }
 
};
 
bool match(char a, char b) {
    return  (a == '(' && b == ')') ||
            (a == '{' && b == '}') ||
            (a == '[' && b == ']');
}

void checkMatch(const Stack<char>& arr) {
    Stack<char> stack(arr.len);
    for (int i=0; i<arr.len; ++i) {
        if (!stack.isempty() && match( stack.top(), arr[i] )) stack.pop();
        else {
            stack.push_back(arr[i]);
            if (arr[i] == ')' || arr[i] == ']' || arr[i] == '}') break;
        }
    }
    if (stack.isempty()) cout << "YES\n";
    else cout << "NO\n";
}

int main(int argc, char const *argv[])
{

    int N, op; char val;
    cin >> N;
    
    Stack<char> stack(N);
 
    while (N--) {
        cin >> op;
        switch (op) {
            case 1: cin >> val; stack.push_back(val); break;
            case 2: if (!stack.isempty()) stack.pop(); break;
            case 3: if (!stack.isempty()) cout << stack.top() << endl; break;
            default: checkMatch(stack);
        }
    }
    return 0;
}
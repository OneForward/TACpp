#include <iostream>
using namespace std;

struct Pair {
    int index;
    int priority;
};

template <class T> struct Queue {
    T* data;
    int head, tail;
    int capacity;
    Queue(int size=127): data{new T[size]}, head{0}, tail{0}, capacity{size} {}

    void push(const T& val) {
        tail = (tail + 1) % capacity;
        data[tail] = val;
    }

    T pop() { 
        head = (head + 1) % capacity;
        return data[head];
    }
    
    bool isempty() const {
        return head == tail;
    }

    void clear() { head = tail = 0; }
};


int main(int argc, char const *argv[])
{
    int T, N, J, priority;
    Queue<Pair> Q;
    
    cin >> T;
    while (T--) {
        // 模拟法，Time O(N^2) Space O(N) 
        int Counter[10]{}, time = 1, cur_priority = 9;;
        Q.clear();

        cin >> N >> J;
        for (int i=0; i<N; ++i) 
            cin >> priority, Q.push({i, priority}), Counter[priority] += 1;

        while (Counter[cur_priority] == 0) cur_priority--;

        while (!Q.isempty()) {
            auto [index, priority] = Q.pop();
            if (priority < cur_priority) Q.push({index, priority});
            else if (index == J) break; 
            else {
                time++; Counter[cur_priority]--;
                while (Counter[cur_priority] == 0) cur_priority--;
            }
        }   
        
        cout << time << endl;      
    }
    return 0;
}

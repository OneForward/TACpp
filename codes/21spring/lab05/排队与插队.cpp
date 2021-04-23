#include <iostream>
using namespace std;

template <class T> struct Queue {
    T* data;
    int head, tail;
    int capacity;
    Queue(int size=3):data{new T[size+1]}, head{0}, tail{0}, capacity{size+1} {}

    void doubleSpace() {
        int old_capacity = capacity;
        auto old_data = data;
        capacity *= 2;
        data = new int[capacity];
        for (int i=1; i<old_capacity; ++i) 
            data[i] = old_data[(head+i)%old_capacity];
        head = 0; tail = old_capacity;
    }

    void push(const T& val) {
        tail = (tail + 1) % capacity;
        if (tail == head) doubleSpace();
        data[tail] = val;
    }

    T pop() { 
        head = (head + 1) % capacity; 
        return data[head];
    }

    T top() { return data[(head + 1) % capacity]; }
    
    bool isempty() const { return head == tail; }

    ~Queue() { delete []data; }

};

int main()
{

    Queue<int> QGroups[10]; // 多个小团体队列
    Queue<int> Qids; // 小团体的编号也是队列

    int N, query, event, G[4005], gid, n = 1;
    cin >> N;
    for (int i=1; i<=N; ++i)  
        cin >> G[i]; // 第i个人归属的团体编号

    cin >> query;
    while (query--) {
        cin >> event; // 事件
        
        if (event == 0) { // 插入新人到所在的小团体后
            if (n > N) continue;

            gid = G[n]; // 第 n 个人归属的团体编号
            // 如果队列中有自己的团体，插到小团体队伍
            if (QGroups[gid].isempty()) Qids.push(gid);
            QGroups[gid].push(n);
            n++;
        }
        else { // 队首离开
            if (Qids.isempty()) {
                cout << -1 << endl; continue;
            }
            
            gid = Qids.top();// 队首的人归属的团体编号，
            // 队首出队
            cout << QGroups[gid].pop() << endl;
            
            // 如果队首的小团体没人了，移除该小团体编号
            if (QGroups[gid].isempty()) Qids.pop();
        }
    }
    return 0;
}

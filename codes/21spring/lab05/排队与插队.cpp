#include <iostream>
using namespace std;

template <class T> struct Queue {
    T* data;
    int head, tail;
    int capacity;
    Queue(int size=3):data{new T[size+1]}, head{0}, tail{0}, capacity{size+1} {}

    void doubleSpace() {
        int old_capacity = capacity;
        T* old_data = data;
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
    
    bool isempty() { return head == tail; }

    ~Queue() { delete []data; }

};

int main(int argc, char const *argv[])
{

    Queue<int> QGroups[20];
    Queue<int> Qids;

    int N, query, flag, G[4005], gid, n = 1;
    cin >> N;
    for (int i=1; i<=N; ++i)  cin >> G[i];

    cin >> query;
    while (query--){
        cin >> flag;
        
        if (flag == 0) {
            if (n > N) continue;

            gid = G[n];
            if (!QGroups[gid].isempty()) QGroups[gid].push(n);
            else Qids.push(gid), QGroups[gid].push(n);
            n++;
        }
        else {
            if (Qids.isempty() || n > N+1) {
                cout << -1 << endl; continue;
            }
            
            gid = Qids.top();
            cout << QGroups[gid].pop() << endl;
            if (QGroups[gid].isempty()) Qids.pop();
        }
    }
    return 0;
}

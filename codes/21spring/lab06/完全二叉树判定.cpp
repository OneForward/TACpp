#include <iostream>

using namespace std;

template <class T> struct Queue {
    T* data;
    int head, tail;
    int capacity;
    
    Queue(int size=127): data{new T[size]}, head{0}, tail{0}, capacity{size} {}

    ~Queue() { delete [] data; }

    void push(const T& val) {
        tail = (tail + 1) % capacity;
        data[tail] = val;
    }

    void pop() { head = (head + 1) % capacity; }

    T front() const { return data[(head + 1) % capacity]; }
    
    bool isempty() const { return head == tail; }

    void clear() { head = tail = 0; }

};

const int null = 0;

struct Node {
    int parent;
    int lchild;
    int rchild;
    
    Node(): parent{null}, lchild{null}, rchild{null} {}
    void set_child(int l, int r) { lchild = l, rchild = r; }
    void set_parent(int p) { parent = p; }
};

int findroot(Node* tree, int N) {
    for (int i=1; i<=N; ++i) 
        if (tree[i].parent == null) return i;
    return 0;
}

bool iscomplete(Node* tree, int root) {
    // 层序遍历，第一次出现 null 之后后面不许再出现 非 null 
    Queue<int> Q; Q.push(root);
    while (not Q.isempty()) {
        auto root = Q.front(); Q.pop();
        if (root == null) break;
        auto rootNode = tree[root];
        Q.push(rootNode.lchild);
        Q.push(rootNode.rchild);
    }
    while (not Q.isempty() and Q.front() == null) Q.pop();
    return Q.isempty();
}


int main()
{
    
    int N, lft, rht;
    cin >> N;

    Node* tree = new Node[N+1] {};
    for (int i=1; i<=N; ++i) {
        cin >> lft >> rht;
        tree[i].set_child(lft, rht);
        tree[lft].set_parent(i);
        tree[rht].set_parent(i);
    }

    int root = findroot(tree, N); 

    if (iscomplete(tree, root)) cout << "Y";
    else cout << "N";
    
    return 0;
}

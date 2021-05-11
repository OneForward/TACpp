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
    return null;
}

void preorder(Node* tree, int root) {
    if (root == null) return;

    cout << root << " ";
    preorder(tree, tree[root].lchild);
    preorder(tree, tree[root].rchild);
}

void inorder(Node* tree, int root) {
    if (root == null) return;

    inorder(tree, tree[root].lchild);
    cout << root << " ";
    inorder(tree, tree[root].rchild);
}

void postorder(Node* tree, int root) {
    if (root == null) return;

    postorder(tree, tree[root].lchild);
    postorder(tree, tree[root].rchild);
    cout << root << " ";
}

void levelOrder(Node* tree, int root) {
    Queue<int> Q(10001); int popNode, lchild, rchild;
    Q.push(root);
    while (!Q.isempty()) {
        popNode = Q.front(); Q.pop();
        cout << popNode << " ";
        lchild = tree[popNode].lchild, rchild = tree[popNode].rchild;
        if (lchild) Q.push(lchild);
        if (rchild) Q.push(rchild);
    } 
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
    
    preorder(tree, root); cout << endl;
    inorder(tree, root); cout << endl;
    postorder(tree, root); cout << endl;
    levelOrder(tree, root); cout << endl;
}

#include <iostream>
using namespace std;

template<class T> struct BNode
{
    T data;
    BNode* lchild{};
    BNode* rchild{};
    BNode* parent{};
    BNode(T d,  BNode* p):  data{d}, parent{p} {}
};

template<class T> struct BSTree
{
    using Node = BNode<T>;
    Node* root = nullptr;

    Node* insert(const T& val) {  return insert(val, root, nullptr); }
    
    Node* insert(const T& val, Node*& node, Node* parent) {
        if (node == nullptr) return node = new Node(val, parent); 
        
        if (val == node->data) return node;
        else if (val < node->data) return insert(val, node->lchild, node);
        else return insert(val, node->rchild, node);
    }
};

int main()
{
    int N, val; 
    cin >> N;

    BSTree<int> tree;
    while (N--) {
        cin >> val;
        auto node = tree.insert(val);
        if (node->parent) cout << node->parent->data << endl;
        else cout << -1 << endl;
    }
    return 0;
}
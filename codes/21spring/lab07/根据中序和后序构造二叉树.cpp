#include <iostream>
using namespace std;

template<typename T> struct Node
{
    T data;
    Node* lchild;
    Node* rchild;

    void preOrder() {
        cout << data << " ";
        if (lchild) lchild->preOrder();
        if (rchild) rchild->preOrder();
    }
};

template<typename T>
Node<T>* buildTree(T* M, int mlft, int mrht, T* P, int plft, int prht) {
    if (mlft > mrht || plft > prht) return nullptr;

    T rootData = P[prht];
    int mroot = mlft;

    while (M[mroot] != rootData) mroot++;

    Node<T>* lchild = buildTree(M, mlft, mroot-1, P, plft, plft+mroot-mlft-1);
    Node<T>* rchild = buildTree(M, mroot+1, mrht, P, plft+mroot-mlft, prht-1);
    
    return new Node<T>{rootData, lchild, rchild};
}



int main()
{
    int N;
    cin >> N;

    int midOrder[10005], postOrder[10005];
    for (int i=0; i<N; ++i) cin >> midOrder[i];
    for (int i=0; i<N; ++i) cin >> postOrder[i];
    
    auto root = buildTree(midOrder, 0, N-1, postOrder, 0, N-1);
    root->preOrder();

    return 0;
}

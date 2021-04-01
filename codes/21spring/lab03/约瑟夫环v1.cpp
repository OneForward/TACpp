/*
约瑟夫环问题
*/
 #include <iostream>
using namespace std;

struct Node {
    int val; 
    Node* next;  
};

int lastRemaining(int N, int M) {
    auto head = new Node{N}, p = head;
    for (int i = N-1; i >= 1; --i) p = new Node{i, p};
    head->next = p; p = head;
    
    for (int len = N; len > 1; --len) { 
        for (int i = 0; i < (M - 1) % len; ++i) p = p->next;
        p->next = p->next->next;
    }
    return p->val;
}

int main()
{
    int N, M;
    cin >> N >> M; 
    
    cout << lastRemaining(N, M);
    return 0;
}
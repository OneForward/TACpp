/*
约瑟夫环问题
*/
#include <iostream>
using namespace std;

struct Node
{
    int nodeValue;
    Node* next;
    Node(int item):nodeValue(item),next(NULL){}
};

int lastRemaining(int n, int m) {
    Node* head = new Node(1), *curr = head, *tmp;
    for (int i = 2; i <= n; i++)
    {
        curr->next = new Node(i);
        curr = curr->next;
    }
    curr->next = head;
    
    // curr 永远指向被删结点的前一个
    int M = m; 
    while (n>1)
    { 
        m = M % n; if (m == 0) m = n;
        while (--m)
            curr = curr->next;
        tmp = curr->next;    
        curr->next = curr->next->next;
        delete tmp;
        n--;
    }
    return curr->nodeValue;
}


int main()
{
    int N, M;
    cin >> N >> M; 
    
    cout << lastRemaining(N, M);
    return 0;
}

#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node *next;
    Node(int x) : val(x), next(NULL) {}
};

int lastRemaining(int n)
{
    Node *head = new Node(1), *curr = head, *tmp;
    for (int i = 2; i <= n; i++)
    {
        curr->next = new Node(i);
        curr = curr->next;
    }
    curr->next = head;

    while (n > 1)
    {
        int m = 3;
        while (--m)
            curr = curr->next;
        tmp = curr->next;
        curr->next = curr->next->next;
        delete tmp;
        n--;
    }
    return curr->val;
}

int main()
{
    int n;
    cin >> n;

    cout << lastRemaining(n);
    return 0;
}

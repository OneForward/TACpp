#include <iostream>
#include <vector>

using namespace std;

template <class T> struct Node {
    T val; 
    Node* next;
};

template <class T> struct Link
{
    using Node = Node<T>;
    Node Head;
    Node* tail{&Head};

    Link() {}
    
    Link(const Link& L) {
        auto p = L.Head.next;
        while (p) push_back(p->val), p = p->next;
    }

    Link(const vector<T>& v) {
        for (auto&& x: v) push_back(x);
    }

    ~Link() {
        auto p = Head.next;
        while (p) {
            auto next = p->next;
            delete p;
            p = next;
        }
    }

    void push_back(const T& val) {
        tail->next = new Node{ val };  tail = tail->next;
    }

    friend ostream& operator<< (ostream& os, const Link& L) {
        auto p = L.Head.next;
        while (p) {
            os << p->val << ", ";
            p = p->next;
        }
        return os;
    }
};




int main(int argc, char const *argv[])
{
    auto link1 = Link<int>( {1, 3, 5, 7, 9} );
    auto link2 = link1;
    cout << link1 << endl;
    cout << link2 << endl;
    return 0;
}

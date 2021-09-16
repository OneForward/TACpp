#include <iostream>
using namespace std;

struct List
{
    int num;
    List *next;
};

int main()
{
    List *head, *p, *q;
    int num;

    head = NULL;
    // cout << "请输入若干个正整数（-1结束）\n";
    cin >> num;
    while(num != -1)
    {
        p = new List;
        p->num = num;
        p->next = head;
        head = p;
        cin >> num;
    }

    // cout << "按照输入顺序逆序输出\n";
    for(p = head; p != NULL; p = p->next)
    {
        cout << p->num << " ";
    };
    cout << endl;

    for(p = head; p != NULL; p = q)
    {
        q = p->next;
        delete p;
    }

    return 0;
}
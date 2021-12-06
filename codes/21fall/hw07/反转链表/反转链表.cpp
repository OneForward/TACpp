#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
};


ListNode* reverseList(ListNode* head) {
    /********* Begin *************/
    ListNode* prev{}, *curr = head;
    while (curr) {
        auto next = curr->next; curr->next = prev;
        prev = curr; curr = next;
    }
    return prev;
    /********* End *************/
}



ListNode* createList() {
    ListNode head{};  auto p = &head; 
    int x;
    while (cin >> x) {
        p->next = new ListNode{x}; 
        p = p->next; 
    }
    return head.next;
}

void disp(ListNode* p) {
    while (p)
    {
        printf("%d -> ", p->val); p = p->next;
    }
    printf("nullptr\n");
}

int main()
{
    auto L1 = createList();    disp(L1);
    auto L2 = reverseList(L1); disp(L2);

    return 0;
}

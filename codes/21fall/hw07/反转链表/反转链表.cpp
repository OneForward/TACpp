#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next = NULL; // C++11 non-static member initialization
};


ListNode* reverseList(ListNode* head) {
    /********* Begin *************/
    ListNode* prev = NULL, *curr = head, *next;
    while (curr) {
        next = curr->next; curr->next = prev;
        prev = curr; curr = next;
    }
    return prev;
    /********* End *************/
}



ListNode* createList() {
    int x;
    ListNode head; 
    ListNode* p = &head; 
    while (cin >> x) {
        p->next = new ListNode; p->next->val = x; p->next->next = NULL;
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
    ListNode* L1 = createList(); disp(L1);
    ListNode* L2 = reverseList(L1); disp(L2);

    return 0;
}

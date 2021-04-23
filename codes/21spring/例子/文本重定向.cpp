#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next = NULL; // C++11 non-static member initialization
};


ListNode* reverseList(ListNode* head) {
    
    ListNode* prev = nullptr, *curr = head;

    while (curr) {
        auto next = curr->next; 

        curr->next = prev;

        prev = curr; curr = next;
    }

    return prev;
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

std::FILE* freopen( const char* filename, const char* mode, std::FILE* stream );

int main()
{
    freopen("in.txt", "r", stdin); // 将文本 in.txt 作为输入流输入
    freopen("out.txt", "w", stdout); // 将文本 out.txt 作为输出流输出

    ListNode* L1 = createList(); disp(L1);
    ListNode* L2 = reverseList(L1); disp(L2);

    return 0;
}

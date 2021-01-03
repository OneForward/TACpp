#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
};


ListNode* reverseList(ListNode* head) {
    /********* Begin *************/
    ListNode *a,*b;
    b=new ListNode;
    b->val=head->val;
    b->next=NULL;
    if (head==NULL) {return NULL;}
    if (head->next==NULL) return b;
    do
    {
       head=head->next;
       a=new ListNode;
       a->val=head->val;
       a->next=b;
       b=a;
    }
    while (head->next!=NULL);
    return b;

    /********* End *************/
}



ListNode* createList() {
    int x;
    ListNode head; 
    ListNode* p = &head; head.next = NULL;
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
    freopen("in.txt", "r", stdin);
    
    ListNode* L1 = createList(); disp(L1);
    ListNode* L2 = reverseList(L1); disp(L2);

    return 0;
}

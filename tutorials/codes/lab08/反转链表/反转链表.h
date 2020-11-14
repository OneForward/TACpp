struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x=0): val(x), next(NULL) {}
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
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* deleteMiddle(ListNode* head) {
    if (!head || !head->next) return nullptr;

    ListNode* prev = nullptr;
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast && fast->next) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
//for extra safety we check prev is not null
    if (prev) prev->next = slow->next;
    delete slow;

    return head;
}

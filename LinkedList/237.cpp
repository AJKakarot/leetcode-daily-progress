struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;      // Step 1: copy next node’s value
        ListNode* temp = node->next;      // Step 2: store next node pointer
        node->next = node->next->next;    // Step 3: skip next node
        delete temp;                      // Step 4: free memory of skipped node
    }
};


 //Copy next → Skip next → Delete next ✅
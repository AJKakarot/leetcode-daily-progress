
 // Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
      ListNode(int x) : val(x), next(nullptr) {}
 };
 

 // Definition for singly-linked list.
 struct ListNode {
      int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
 };
 

class Solution {
public:
    void deleteNode(ListNode* node) {

        ListNode* prev = nullptr;

        // Move through the list until we reach the last node
        while (node != nullptr && node->next != nullptr) {
            node->val = node->next->val;  // Copy next node's value
            prev = node;
            node = node->next;
        }

        // Now 'node' is last node and 'prev' is second last
        prev->next = nullptr;

        // Delete last node
        delete node;
    }
};

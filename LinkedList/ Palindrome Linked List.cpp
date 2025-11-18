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
    ListNode* curr; // global pointer to track head during recursion

    bool recur(ListNode* head) {
        if (head == nullptr) {
            return true; // base case
        }

        // Recursively check the rest of the list
        bool ans = recur(head->next);

        // If already false, propagate
        if (!ans)
            return false;

        // Compare current node with mirrored node
        if (head->val != curr->val)
            return false;

        // Move curr forward
        curr = curr->next;

        return true;
    }

    bool isPalindrome(ListNode* head) {
        curr = head;
        return recur(head);
    }
};
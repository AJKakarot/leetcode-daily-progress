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
 
 /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:

    // Helper function to reverse k nodes
    ListNode* reverseKNodes(ListNode* head, int k) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;
        int count = 0;

        while (curr != nullptr && count < k) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        return prev; // new head after reversal
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || k == 1) return head;

        // Step 1: check if there are at least k nodes
        ListNode* temp = head;
        int count = 0;
        while (temp != nullptr && count < k) {
            temp = temp->next;
            count++;
        }

        if (count < k) {
            // Less than k nodes → return head as-is
            return head;
        }

        // Step 2: reverse first k nodes
        ListNode* newHead = reverseKNodes(head, k);

        // Step 3: recursively process the remaining list
        head->next = reverseKGroup(temp, k);

        return newHead;
    }
};
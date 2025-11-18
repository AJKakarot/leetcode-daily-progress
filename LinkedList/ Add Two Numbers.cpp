
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        // Dummy node to simplify list construction
        ListNode* result = new ListNode(0);
        ListNode* ptr = result;

        int carry = 0;  // Initial carry

        // Process until both lists finish
        while (l1 != nullptr || l2 != nullptr) {

            int sum = carry;   // Start sum from carry

            // Add from l1
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }

            // Add from l2
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }

            // Update carry and digit
            carry = sum / 10;
            int digit = sum % 10;

            // Add digit to result list
            ptr->next = new ListNode(digit);
            ptr = ptr->next;
        }

        // If carry left after processing both lists
        if (carry == 1) {
            ptr->next = new ListNode(1);
        }

        return result->next;  // Skip dummy node
    }
};

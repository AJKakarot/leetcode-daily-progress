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
    // Function to return the middle node of a singly linked list
    ListNode* middleNode(ListNode* head) {

        // Initialize two pointers: slow and fast
        ListNode* slow = head;
        ListNode* fast = head;

       
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;           // 1 step
            fast = fast->next->next;     // 2 steps
        }

        // Slow pointer is now at the middle node
        return slow;
    }
};

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* temp = head;

        // Move temp n steps forward
        for (int i = 1; i <= n; i++) {
            temp = temp->next;
        }

        // Case 1: temp becomes NULL → we are deleting the HEAD
        // That means n == length of list
        if (temp == nullptr) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        // Case 2: Normal case → move temp & prev together
        ListNode* prev = head;
        while (temp->next != nullptr) {
            prev = prev->next;        // move prev
            temp = temp->next;        // move temp
        }

        // Now prev->next is the node to delete
        ListNode* delNode = prev->next;
        prev->next = prev->next->next;
        delete delNode;

        return head;
    }
};

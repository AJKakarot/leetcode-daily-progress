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

    int getLength(ListNode* head) {
        ListNode* temp = head;
        int count = 0;
        while (temp != nullptr) {
            temp = temp->next;
            count++;
        }
        return count;
    }

    ListNode* getIntersectionNode(ListNode *headA, ListNode *headB) {

        int lenA = getLength(headA);
        int lenB = getLength(headB);

        // Move bigger list ahead
        while (lenA > lenB) {
            headA = headA->next;
            lenA--;
        }
        while (lenB > lenA) {
            headB = headB->next;
            lenB--;
        }

        // Now move both pointers together
        while (headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }

        return headA;  // can be intersection node or NULL
    }
};
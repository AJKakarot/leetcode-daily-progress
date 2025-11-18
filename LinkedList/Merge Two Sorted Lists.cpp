
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
    // Function to merge two sorted linked lists using recursion
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        // Base Cases:
        // If any list becomes empty, return the other list
        if (list1 == nullptr)
            return list2;
        if (list2 == nullptr)
            return list1;

        ListNode* result = nullptr;

        /*
            Compare current nodes of both lists.
            Whichever node has a smaller value becomes the head of the merged
           list.

            Then recursively merge when:
            - If list1 smaller → merge (list1->next, list2)
            - If list2 smaller → merge (list1, list2->next)
        */
        if (list1->val < list2->val) {
            result = list1;
            result->next = mergeTwoLists(list1->next, list2);
        } else {
            result = list2;
            result->next = mergeTwoLists(list1, list2->next);
        }

        return result;
    }
};

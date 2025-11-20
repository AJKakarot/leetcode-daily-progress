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
    // Recursive function to reverse a linked list
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) // Base case: empty list or single node
            return head;

        ListNode* last = reverseList(head->next); // Reverse rest of the list
        head->next->next = head; // Make next node point to current
        head->next = nullptr;    // Break current node's next pointer
        return last;             // Return new head
    }

    // Function to get the length of the linked list
    int getListLength(ListNode* head) {
        int count = 0;
        ListNode* temp = head;
        while (temp) {
            count++; // Count nodes
            temp = temp->next;
        }
        return count;
    }

    // Main function to rotate the linked list to the right by k places
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head)
            return head; // Empty list edge case

        int length = getListLength(head); // Find total length
        k = k % length;                   // Adjust k if larger than length
        if (k == 0)
            return head; // No rotation needed

        head = reverseList(head); // Step 1: Reverse the entire list

        // Step 2: Traverse first k nodes in reversed list
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr && curr->next && k > 0) {
            k--;
            prev = curr;
            curr = curr->next;
        }

        if (prev)
            prev->next = nullptr; // Break the list into two parts

        curr = reverseList(
            curr); // Step 3: Reverse last part (first k nodes in original)
        ListNode* newHead =
            reverseList(head); // Step 4: Reverse first part (rest of list)

        // Step 5: Connect reversed first part to reversed last part
        ListNode* temp = newHead;
        while (temp && temp->next) {
            temp = temp->next;
        }
        if (temp)
            temp->next = curr;

        return newHead; // Return rotated list
    }
};

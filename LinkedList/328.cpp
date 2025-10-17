 struct ListNode {
      int val;
      ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        // Base case: empty list or single node
        if (head == nullptr || head->next == nullptr) 
            return head;

        // Initialize pointers
        ListNode* odd = head;          // Odd positioned nodes
        ListNode* even = head->next;   // Even positioned nodes
        ListNode* evenHead = even;     // Save head of even list to connect later

        // Reorder list: separate odd and even nodes
        while (even != nullptr && even->next != nullptr) {
            odd->next = even->next;    // Connect current odd to next odd
            odd = odd->next;           // Move odd pointer forward

            even->next = even->next->next; // Connect current even to next even
            even = even->next;             // Move even pointer forward
        }

        // Connect end of odd list to head of even list
        odd->next = evenHead;

        return head; // Return reordered list
    }
};
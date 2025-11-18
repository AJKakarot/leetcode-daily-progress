/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        if (head == nullptr || head->next == nullptr) {
            return nullptr;  // no cycle
        }

        ListNode* slow = head;
        ListNode* fast = head;

        // Step 1: Detect if cycle exists
        bool hasCycle = false;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                hasCycle = true;
                break;
            }
        }

        if (!hasCycle) return nullptr;  // no cycle

        // Step 2: Find start of cycle
        ListNode* ptr = head;
        while (ptr != slow) {
            ptr = ptr->next;
            slow = slow->next;
        }

        return ptr;  // start of cycle
    }
};
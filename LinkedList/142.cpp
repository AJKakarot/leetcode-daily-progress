// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    // Function to detect the start of a cycle in a linked list
    ListNode* detectCycle(ListNode* head) {
        // Base case: empty list or single-node list → no cycle
        if (!head || !head->next) return nullptr;

        // Initialize two pointers for Floyd’s Tortoise & Hare algorithm
        ListNode* tortoise = head;  // slow pointer moves 1 step
        ListNode* hare = head;      // fast pointer moves 2 steps

        // Phase 1: Detect cycle
        while (hare && hare->next) {
            tortoise = tortoise->next;         // move slow pointer 1 step
            hare = hare->next->next;           // move fast pointer 2 steps

            if (tortoise == hare) {            // pointers meet → cycle detected
                break;
            }
        }

        // If fast pointer reached the end → no cycle
        if (tortoise != hare) return nullptr;

        // Phase 2: Find the start of the cycle
        ListNode* pointerFromHead = head;      // start from head
        while (pointerFromHead != tortoise) {  // move both 1 step at a time
            pointerFromHead = pointerFromHead->next;
            tortoise = tortoise->next;
        }

        // Both pointers meet at the start of the cycle
        return pointerFromHead;
    }
};
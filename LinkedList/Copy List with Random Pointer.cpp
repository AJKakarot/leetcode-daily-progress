 // Definition for singly-linked list with random pointer.
 struct Node {
     int val;
     Node *next;
     Node *random;
     Node(int x) : val(x), next(nullptr), random(nullptr) {}
 };


class Solution {
public:
    Node* copyRandomList(Node* head) {
        // Step 0: Edge case - if the original list is empty, return NULL
        if (!head)
            return nullptr;

        Node* curr = head;

        // Step 1: Insert copied nodes in between original nodes
        while (curr) {
            Node* currNext = curr->next; // Store next node
            curr->next =
                new Node(curr->val); // Create new copy node after current
            curr->next->next =
                currNext;    // Connect copy node to next original node
            curr = currNext; // Move to next original node
        }

        // Step 2: Copy random pointers
        curr = head;
        while (curr && curr->next) {
            if (curr->random == nullptr) {
                curr->next->random = nullptr; // If original random is NULL
            } else {
                curr->next->random =
                    curr->random->next; // Copy random to corresponding new node
            }
            curr = curr->next->next; // Move to next original node
        }

        // Step 3: Separate the copied list from original list
        Node* newHead = head->next; // Head of copied list
        Node* newCurr = newHead;
        curr = head;

        while (curr && newCurr) {
            curr->next = curr->next ? curr->next->next
                                    : nullptr; // Restore original next pointer
            newCurr->next = newCurr->next
                                ? newCurr->next->next
                                : nullptr; // Set next pointer for copy
            curr = curr->next;             // Move to next original node
            newCurr = newCurr->next;       // Move to next copied node
        }

        return newHead; // Return head of deep copied list
    }
};

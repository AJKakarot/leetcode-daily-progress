
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = nullptr;
        bottom = nullptr;
    }
};


class Solution {
public:

    // Helper function to merge two sorted bottom lists
    Node* merge(Node* a, Node* b) {
        if (!a) return b;
        if (!b) return a;

        Node* result;

        if (a->data < b->data) {
            result = a;
            result->bottom = merge(a->bottom, b);
        } else {
            result = b;
            result->bottom = merge(a, b->bottom);
        }

        return result;
    }

    Node* flatten(Node* root) {
        if (!root || !root->next) {
            return root; // base case
        }

        // Recursively flatten next linked list
        Node* flatNext = flatten(root->next);

        // Merge current list with flattened next
        return merge(root, flatNext);
    }
};

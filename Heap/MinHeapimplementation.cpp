#include <iostream>  // Includes input-output stream library for using cout, cin
#include <vector>    // Includes vector library to use dynamic arrays (vector)
using namespace std; // Allows use of standard names without 'std::' prefix

// Class representing a Min Heap
class MinHeap
{
private:
    vector<int> heap; // Vector to store elements of the heap

    // Helper functions to calculate parent and child indices
    int parent(int i) { return (i - 1) / 2; }   // Parent index of node i
    int leftChild(int i) { return 2 * i + 1; }  // Left child index of node i
    int rightChild(int i) { return 2 * i + 2; } // Right child index of node i

    // Maintain heap property after inserting a new element
    void heapifyUp(int i)
    {
        // Continue until the node reaches the root or the parent is smaller
        while (i > 0 && heap[parent(i)] > heap[i])
        {
            // Swap if the parent is larger than the current element
            swap(heap[parent(i)], heap[i]);
            // Move index to parent for next comparison
            i = parent(i);
        }
    }

    // Maintain heap property after deleting an element
    void heapifyDown(int i)
    {
        int smallest = i;          // Assume current node is smallest
        int left = leftChild(i);   // Get left child index
        int right = rightChild(i); // Get right child index

        // Compare left child with current smallest
        if (left < heap.size() && heap[left] < heap[smallest])
            smallest = left;

        // Compare right child with current smallest
        if (right < heap.size() && heap[right] < heap[smallest])
            smallest = right;

        // If smallest is not the current node, swap and continue heapifying
        if (smallest != i)
        {
            swap(heap[i], heap[smallest]);
            heapifyDown(smallest); // Recursively fix the affected subtree
        }
    }

public:
    // Insert a new element into the heap
    void push(int x)
    {
        heap.push_back(x);          // Add new element at the end
        heapifyUp(heap.size() - 1); // Fix heap property from bottom to top
    }

    // Remove the smallest (root) element from the heap
    void pop()
    {
        if (heap.empty())
            return; // If heap is empty, do nothing

        heap[0] = heap.back(); // Move last element to the root
        heap.pop_back();       // Remove last element

        if (!heap.empty())  // If heap not empty, fix heap property
            heapifyDown(0); // Start from root
    }

    // Return the smallest element (root of the heap)
    int peek()
    {
        if (heap.empty())
            return -1;  // Return -1 if heap is empty
        return heap[0]; // Return root element (min element)
    }

    // Return the number of elements in heap
    int size()
    {
        return heap.size(); // Return vector size
    }

    // Print all elements of the heap (for debugging or display)
    void printHeap()
    {
        for (int x : heap)    // For each element in vector
            cout << x << " "; // Print element
        cout << endl;         // End line after printing
    }
};

// Driver code to test MinHeap
int main()
{
    MinHeap h; // Create a MinHeap object

    // Insert elements into the heap
    h.push(10);
    h.push(5);
    h.push(20);
    h.push(3);

    cout << "Heap elements: ";
    h.printHeap(); // Print all heap elements

    cout << "Min element: " << h.peek() << endl; // Display smallest element (root)

    h.pop(); // Remove the min element
    cout << "After removing min: ";
    h.printHeap(); // Print heap after deletion

    cout << "Current size: " << h.size() << endl; // Print current heap size

    return 0; // Exit program successfully
}

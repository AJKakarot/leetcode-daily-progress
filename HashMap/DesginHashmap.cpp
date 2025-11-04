// ===============================================================
// ✅ Custom HashMap Implementation in C++ using STL
// Features:
// - Insert, Retrieve, and Delete key-value pairs
// - Handles collisions using Separate Chaining (lists inside vector)
// - STL used: vector, list, pair, swap
// ===============================================================

#include <iostream> // For std::cout, std::endl
#include <vector>   // For std::vector to store buckets
#include <list>     // For std::list to handle collisions
using namespace std;

// Custom HashMap Class
class MyHashMap
{
private:
    // Total number of buckets in the hash table
    static const int SIZE = 1000;

    // Vector of lists to store key-value pairs
    // Each index in vector is a bucket (list) that handles collisions
    vector<list<pair<int, int>>> table;

    // Simple hash function: maps a key to a bucket index
    int hash(int key)
    {
        return key % SIZE;
    }

public:
    // Constructor: Initializes the hash table with SIZE empty buckets
    MyHashMap() : table(SIZE) {}

    // 🔹 Insert a key-value pair into the hashmap
    // If the key already exists, update its value
    void put(int key, int value)
    {
        int index = hash(key); // Compute bucket index
        for (auto &p : table[index])
        { // Traverse the bucket
            if (p.first == key)
            {                     // Key already exists
                p.second = value; // Update its value
                return;           // Exit after updating
            }
        }
        table[index].push_back({key, value}); // Key not found → insert new pair
    }

    // 🔹 Retrieve value for a given key
    // Returns -1 if key does not exist
    int get(int key)
    {
        int index = hash(key); // Compute bucket index
        for (auto &p : table[index])
        { // Traverse the bucket
            if (p.first == key)
            {                    // Key found
                return p.second; // Return value
            }
        }
        return -1; // Key not found
    }

    // 🔹 Remove a key-value pair from the hashmap
    void remove(int key)
    {
        int index = hash(key); // Compute bucket index
        for (auto it = table[index].begin(); it != table[index].end(); ++it)
        {
            if (it->first == key)
            {                           // Key found
                table[index].erase(it); // Remove it from the list
                return;                 // Exit after removal
            }
        }
    }

    // 🔹 Debug function: Print all elements in the hashmap
    void printHashMap()
    {
        cout << "HashMap Contents:\n";
        for (int i = 0; i < SIZE; i++)
        {
            if (!table[i].empty())
            {
                cout << "Bucket " << i << ": ";
                for (auto &p : table[i])
                    cout << "(" << p.first << "," << p.second << ") ";
                cout << endl;
            }
        }
    }
};

// ====================== DRIVER CODE ==========================
int main()
{
    MyHashMap obj; // Create hashmap object

    // Insert key-value pairs
    obj.put(1, 10);
    obj.put(2, 20);
    obj.put(1001, 99); // Collision with key 1 (hash: 1 % 1000)

    // Print current hashmap
    obj.printHashMap();

    // Retrieve values
    cout << "Get key 2: " << obj.get(2) << endl; // Output: 20
    cout << "Get key 1: " << obj.get(1) << endl; // Output: 10
    cout << "Get key 3: " << obj.get(3) << endl; // Output: -1 (not found)

    // Remove a key
    obj.remove(1);
    cout << "After removing key 1:\n";
    obj.printHashMap();

    // Try to get removed key
    cout << "Get key 1: " << obj.get(1) << endl; // Output: -1

    return 0;
}

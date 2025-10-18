#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> mp;

        // Step 1: Count frequency using normal for loop
        for (int i = 0; i < arr.size(); i++) {
            mp[arr[i]]++;
        }

        unordered_set<int> st;

        // Step 2: Check if all frequencies are unique
        // Using iterator-based for loop
        for (auto it = mp.begin(); it != mp.end(); it++) {
            int freq = it->second;

            if (st.find(freq) != st.end()) {
                return false; // Frequency already exists
            }
            st.insert(freq);
        }

        return true; // All frequencies were unique
    }
};

#include <vector>
#include <unordered_map>
#include <queue>
#include <utility>
#include <functional>

using namespace std;

class Solution {
public:
    typedef pair<int, int> p; // p.first = frequency, p.second = element
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        // Step 1: Count frequency of each number
        unordered_map<int, int> mp;
        for(int num : nums) {
            mp[num]++; // increases count for each number
        }
        
        // Step 2: Create a min-heap that stores {frequency, number}
        priority_queue<p, vector<p>, greater<p>> pq;
        
        // Step 3: Traverse the frequency map
        for(auto it : mp) {
            pq.push({it.second, it.first});  // Push (freq, num)
            
            // If heap size becomes more than k, remove the least frequent element
            if(pq.size() > k) {
                pq.pop();
            }
        }
        
        // Step 4: Extract the remaining elements from the heap → these are top k frequent
        vector<int> result;
        while(!pq.empty()) {
            result.push_back(pq.top().second); // we only need the number, not frequency
            pq.pop();
        }
        
        return result;
    }
};

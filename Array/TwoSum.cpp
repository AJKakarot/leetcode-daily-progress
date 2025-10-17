#include <vector>
#include <map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        int n = nums.size();           // Get the size of the array

        // Create a map to store values and their indices
        std::map<int,int> mp;

        for (int i = 0; i < n; i++) {
            int remaining = target - nums[i];  // The value needed to reach target

            // Check if the remaining value already exists in the map
            if (mp.find(remaining) != mp.end()) {
                // If found, return the pair of indices
                return {mp[remaining], i};
            }

            // Otherwise, store the current number and its index in the map
            mp[nums[i]] = i;
        }

        // If no pair found, return empty vector
        return {};
    }
};


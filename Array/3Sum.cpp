#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // ✅ Helper function to find 2-sum for each fixed number (-target)
    void twoSum(vector<int>& nums, int left, vector<vector<int>>& result, int target) {
        int right = nums.size() - 1;

        while (left < right) {
            int sum = nums[left] + nums[right];

            if (sum > target) 
                right--;   // Move right pointer left (decrease sum)
            else if (sum < target) 
                left++;    // Move left pointer right (increase sum)
            else {
                // Found a valid triplet
                result.push_back({-target, nums[left], nums[right]});

                // ✅ Skip duplicate values to avoid repeating triplets
                while (left < right && nums[left] == nums[left + 1]) left++;
                while (left < right && nums[right] == nums[right - 1]) right--;

                left++;   // ✅ Always move both after storing result
                right--;
            }
        }
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.size() < 3) return result;   // ✅ Edge case

        sort(nums.begin(), nums.end());        // ✅ Sorting is MUST for two-pointer

        for (int i = 0; i < nums.size() - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) 
                continue;  // ✅ Skip duplicates for first element

            twoSum(nums, i + 1, result, -nums[i]); // Look for 2 numbers that sum to -nums[i]
        }
        return result;
    }
};

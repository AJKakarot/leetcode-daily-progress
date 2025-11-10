#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        
        // Initialize both current and overall maximum sum with first element
        int currMaxSum = nums[0];
        int maxSum = nums[0];
        
        // Loop from the second element
        for (int i = 1; i < n; i++) {
            // Either extend the current subarray or start a new one
            currMaxSum = max(nums[i], currMaxSum + nums[i]);
            
            // Update overall maximum sum
            maxSum = max(maxSum, currMaxSum);
        }

        return maxSum; // Final result: largest subarray sum
    }
};
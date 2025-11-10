#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        
        int n = nums.size();
        int maxSum = nums[0];
        int currMaxSum = nums[0];
        int minSum = nums[0];
        int currMinSum = nums[0];

        for (int i = 1; i < n; i++) {
            currMaxSum = max(nums[i], currMaxSum + nums[i]);  
            maxSum = max(maxSum, currMaxSum);

            currMinSum = min(nums[i], currMinSum + nums[i]);  
            minSum = min(minSum, currMinSum);
        }

        return max(abs(minSum), abs(maxSum));  
 

    }
};
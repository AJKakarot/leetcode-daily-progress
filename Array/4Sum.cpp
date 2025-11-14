#include <iostream>
#include <vector>
using namespace std;



class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        // Step 1: Sort the array to handle duplicates and use 2-pointers
        sort(nums.begin(), nums.end());

        // This vector will store the final list of unique quadruplets
        vector<vector<int>> ans;

        int n = nums.size(); // size of the input array

        // Step 2: First loop to fix the first element of the quadruplet
        for (int i = 0; i < n; i++) {

            // Skip duplicate values for i (first number)
            // If nums[i] == nums[i-1], we already processed this number
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            // Step 3: Second loop to fix the second element
            for (int j = i + 1; j < n; j++) {

                // Skip duplicate values for j (second number)
                // If nums[j] == nums[j-1], then it's repeating
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;

                // Step 4: Calculate the remaining sum we need for the last two
                // numbers Use long long to prevent overflow (very important)
                long long remaining = (long long)target - nums[i] - nums[j];

                // Two pointers for the remaining two elements
                int l = j + 1;
                int r = n - 1;

                // Step 5: Use two-pointer technique
                while (l < r) {

                    long long sum = nums[l] + nums[r];

                    if (sum == remaining) {
                        // We found a valid quadruplet!
                        ans.push_back({nums[i], nums[j], nums[l], nums[r]});

                        // Move both pointers, but skip duplicates
                        int leftVal = nums[l];
                        int rightVal = nums[r];

                        // Skip duplicates for l
                        while (l < r && nums[l] == leftVal)
                            l++;

                        // Skip duplicates for r
                        while (l < r && nums[r] == rightVal)
                            r--;
                    }

                    else if (sum < remaining) {
                        // If sum is smaller, move left pointer to increase sum
                        l++;
                    }

                    else {
                        // If sum is larger, move right pointer to decrease sum
                        r--;
                    }
                }
            }
        }

        // Return the list of all unique quadruplets
        return ans;
    }
};

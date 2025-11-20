#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;    // Tracks current streak of consecutive 1s
        int maxCount = 0; // Stores the maximum streak found so far

        for (int num : nums) { // Loop through each number in the array
            if (num == 1) {    // If current element is 1
                count++;       // Increase current consecutive 1s count
                maxCount = max(maxCount, count); // Update max streak
            } else {
                count = 0; // Reset count when a 0 appears
            }
        }

        return maxCount; // Return the longest consecutive 1s
    }
};

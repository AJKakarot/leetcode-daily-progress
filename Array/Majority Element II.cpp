#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1 = 0, count2 = 0;
        int maj1 = 0, maj2 = 0;

        // Step 1: Find potential candidates
        for (int num : nums) {
            if (num == maj1) count1++;
            else if (num == maj2) count2++;
            else if (count1 == 0) maj1 = num, count1 = 1;
            else if (count2 == 0) maj2 = num, count2 = 1;
            else count1--, count2--;
        }

        // Step 2: Verify candidates
        count1 = count2 = 0;
        for (int num : nums) {
            if (num == maj1) count1++;
            else if (num == maj2) count2++;
        }

        // Step 3: Collect valid results
        vector<int> result;
        int n = nums.size();
        if (count1 > n / 3) result.push_back(maj1);
        if (count2 > n / 3) result.push_back(maj2);

        return result;
    }
};


#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int maj = 0; // stores the current majority candidate

        for (int i = 0; i < nums.size(); i++) {
            // When count is 0, choose a new candidate
            if (count == 0) {
                maj = nums[i];
                count = 1;
            }
            // If current element equals the candidate → increase count
            else if (nums[i] == maj) {
                count++;
            }
            // Otherwise → decrease count
            else {
                count--;
            }
        }

        return maj; // final majority candidate
    }
};

/*
🔹 Majority Element (> n/2)

Uses Boyer–Moore Voting Algorithm → keeps 1 candidate and a count.

Time: O(n), Space: O(1)

🔹 Majority Element (> n/3)

Uses Extended Boyer–Moore Algorithm → keeps 2 candidates and counts.

Time: O(n), Space: O(1)  */

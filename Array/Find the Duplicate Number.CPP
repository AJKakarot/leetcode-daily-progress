#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Step 1: Initialize slow and fast pointers
        int slow = nums[0];
        int fast = nums[0];

        // Step 2: Detect intersection point inside the cycle
        do {
            slow = nums[slow];          // move slow by 1 step
            fast = nums[nums[fast]];    // move fast by 2 steps
        } while (slow != fast);

        // Step 3: Find the entry point of the cycle (duplicate)
        slow = nums[0];                 // reset slow to start
        while (slow != fast) {
            slow = nums[slow];          // move slow by 1 step
            fast = nums[fast];          // move fast by 1 step
        }

        // Step 4: Return the duplicate number
        return slow;
    }
};

// Example usage:
int main() {
    Solution sol;

    vector<int> nums1 = {1, 3, 4, 2, 2};
    cout << "Duplicate: " << sol.findDuplicate(nums1) << endl; // Output: 2

    vector<int> nums2 = {3, 1, 3, 4, 2};
    cout << "Duplicate: " << sol.findDuplicate(nums2) << endl; // Output: 3

    vector<int> nums3 = {1, 1};
    cout << "Duplicate: " << sol.findDuplicate(nums3) << endl; // Output: 1

    return 0;
}

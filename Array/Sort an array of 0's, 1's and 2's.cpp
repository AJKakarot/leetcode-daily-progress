#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int i = 0;         // Pointer for 0 (low)
        int j = 0;         // Pointer for 1 (mid)
        int k = n - 1;     // Pointer for 2 (high)

        while (j <= k) {
            if (nums[j] == 0) {              // Case 0 → swap to front
                swap(nums[i], nums[j]);
                i++;
                j++;
            } 
            else if (nums[j] == 1) {         // Case 1 → already in right place
                j++;
            } 
            else {                           // Case 2 → swap to end
                swap(nums[j], nums[k]);
                k--;
            }
        }
    }
};

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();       // total number of elements
        int golaIndex = -1;        // to store the index of the first decreasing element from the right

        // STEP 1️⃣ : Find the "breaking point" where nums[i] > nums[i - 1]
        // This means nums[i-1] can be increased to form a bigger permutation.
        for (int i = n - 1; i > 0; i--) {
            if (nums[i] > nums[i - 1]) {
                golaIndex = i - 1;  // store this index
                break;              // stop when found
            }
        }

        // STEP 2️⃣ : If such an index was found, find the next greater element on the right
        if (golaIndex != -1) {
            int swapIndex = golaIndex;

            // Search from the end to find the first element greater than nums[golaIndex]
            for (int j = n - 1; j > golaIndex; j--) {
                if (nums[j] > nums[golaIndex]) {
                    swapIndex = j;  // found the number just bigger than nums[golaIndex]
                    break;
                }
            }

            // Swap them so that we make the next larger permutation
            swap(nums[golaIndex], nums[swapIndex]);
        }

        // STEP 3️⃣ : Reverse the part of array after golaIndex
        // Because the suffix is currently in descending order,
        // reversing it will make it the smallest possible (ascending order).
        reverse(nums.begin() + golaIndex + 1, nums.end());
    }
};

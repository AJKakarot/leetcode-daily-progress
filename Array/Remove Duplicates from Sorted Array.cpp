#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int n = nums.size();
        if (n == 0)
            return 0;

        int i = 0; // points to last unique element
        int j = 1; // scans the array

        while (j < n) {
            if (nums[i] != nums[j]) { // new unique element found
                i++;                  // move i to next position
                nums[i] = nums[j];    // place unique element
            }
            j++; // move j to scan next element
        }

        return i + 1; // number of unique elements
    }
};

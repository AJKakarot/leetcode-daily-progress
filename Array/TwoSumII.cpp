

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        int i = 0;
        int j = numbers.size() - 1;   // ❗ must be size()-1, since indices start from 0

        while (i < j) {
            int sum = numbers[i] + numbers[j];

            if (sum == target) {
                return {i + 1, j + 1};   // ✅ output is 1-based index
            }
            else if (sum < target) {
                i++;  // move left pointer rightwards to increase sum
            }
            else {
                j--;  // move right pointer leftwards to decrease sum
            }
        }

        return {};  // if no pair found
    }
};

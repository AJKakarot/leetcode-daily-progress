///What count() Does
//unordered_set.count(x) checks how many times x exists in the set.
//Since sets contain unique elements, count() can only return:
//0 → element not found in the set
//1 → element found in the set

#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        // Convert both arrays to unordered sets for O(1) lookup
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> set2(nums2.begin(), nums2.end());
        
        vector<int> distinct_nums1, distinct_nums2;

        // Elements in nums1 not in nums2
        for (int num : set1) {
            if (set2.count(num) == 0) {
                distinct_nums1.push_back(num);
            }
        }

        // Elements in nums2 not in nums1
        for (int num : set2) {
            if (set1.count(num) == 0) {
                distinct_nums2.push_back(num);
            }
        }

        // Return result as 2D vector
        return {distinct_nums1, distinct_nums2};
    }
};

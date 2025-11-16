#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code // Map: prefixSum → first index where this prefixSum appeared
    unordered_map<int, int> firstSeen;

    int prefSum = 0;
    int res = 0;

    for (int i = 0; i < arr.size(); i++) {

        prefSum += arr[i];

        // Case 1: If prefix sum itself equals k
        // Subarray from index 0 to i
        if (prefSum == k) {
            res = max(res, i + 1);
        }

        // Case 2: If (prefSum - k) was seen before
        // then subarray (indexAfterPrevious + 1 → i) has sum k
        if (firstSeen.find(prefSum - k) != firstSeen.end()) {
            int prevIndex = firstSeen[prefSum - k];
            res = max(res, i - prevIndex);
        }

        // Case 3: Store only FIRST occurrence of prefSum
        if (firstSeen.find(prefSum) == firstSeen.end()) {
            firstSeen[prefSum] = i;
        }
    }

    return res;

        
    }
};
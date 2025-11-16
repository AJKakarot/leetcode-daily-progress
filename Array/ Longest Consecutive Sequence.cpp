#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        // Map to store: number → explored (true/false)
        unordered_map<int, bool> exploredMap;

        // Step 1: Insert all numbers and mark them "not explored"
        for (int num : nums) {
            exploredMap[num] = false;
        }

        int longestLength = 0;

        // Step 2: For each number, expand in both directions
        for (int num : nums) {

            // If already explored, skip (avoid double counting)
            if (exploredMap[num] == true) {
                continue;
            }

            // Mark this number explored
            exploredMap[num] = true;

            int currentLength = 1;

         
            // EXPAND IN FORWARD DIRECTION
         
            int nextNum = num + 1;

            while (exploredMap.find(nextNum) != exploredMap.end() &&
                   exploredMap[nextNum] == false) {

                exploredMap[nextNum] = true;
                currentLength++;
                nextNum++;
            }

        
            // EXPAND IN BACKWARD DIRECTION
           
            int prevNum = num - 1;

            while (exploredMap.find(prevNum) != exploredMap.end() &&
                   exploredMap[prevNum] == false) {

                exploredMap[prevNum] = true;
                currentLength++;
                prevNum--;
            }

            // Update longest streak found so far
            longestLength = max(longestLength, currentLength);
        }

        return longestLength;
    }
};

#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> charSet;
        int left = 0;
        int maxLength = 0;

        for (int right = 0; right < s.length(); right++) {

            // If character already exists, shrink window from left
            while (charSet.count(s[right])) {
                charSet.erase(s[left]);
                left++;
            }

            // Add new character
            charSet.insert(s[right]);

            // Update max length
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};
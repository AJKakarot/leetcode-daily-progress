#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        unordered_map<int, int> freq;  
        int prefixXor = 0;
        int count = 0;

        // a prefix XOR of 0 has appeared once
        freq[0] = 1;

        for (int i = 0; i < arr.size(); i++) {

            prefixXor ^= arr[i];

            // We want: prefixXor ^ needed = k
            // → needed = prefixXor ^ k
            int needed = prefixXor ^ k;

            // If needed exists, add its frequency
            if (freq.find(needed) != freq.end()) {
                count += freq[needed];
            }

            // Store this prefix XOR in map
            freq[prefixXor]++;
        }

        return count;
    }
};

        

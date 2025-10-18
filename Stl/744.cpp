#include <vector>
using namespace std;

//method-1
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();
        int l = 0, r = n - 1;
        int pos = -1;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (letters[mid] > target) {
                pos = mid;     // possible answer
                r = mid - 1;   // try to find smaller valid letter
            } else {
                l = mid + 1;   // search in right half
            }
        }

        // If no letter is greater, wrap around and give the first element
        if (pos == -1) {
            return letters[0];
        }
        return letters[pos];
    }
};


//method-2

//upper_bound(begin, end, value) -> Finds first element > value in sorted list.
//Return first element if it == letters.end() ->	To handle circular condition (no greater character).
//Time Complexity -> O(log n) because upper_bound uses binary search.
//Space Complexity -> O(1)

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        auto it = upper_bound(letters.begin(), letters.end(), target);

        // If iterator reaches end, no element is greater → return first (wrap around)
        if (it == letters.end()) {
            return letters[0];
        }

        return *it; // Otherwise return the found element
    }
};

#include <string>
#include <vector>

using namespace std;

//method-1
class Solution {
public:
    // ✅ Helper function to check palindrome
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.size() - 1;

        while (i < j) {
            if (s[i] != s[j]) 
                return false; // Not a palindrome
            i++;
            j--;
        }
        return true; // Palindrome
    }

    // ✅ Main function to return the first palindrome word
    string firstPalindrome(vector<string>& words) {
        for (string word : words) {
            if (isPalindrome(word))   // ✅ Check for palindrome
                return word;          // Return first match
        }
        return ""; // If no palindrome found
    }
};


//method-2

#include <algorithm> // for reverse

class Solution {
public:
    // ✅ Check palindrome using STL
    bool isPalindrome(string s) {
        string temp = s;
        reverse(temp.begin(), temp.end()); // STL reverse
        return temp == s; // Compare original with reversed
    }

    // ✅ Return first palindrome from the list
    string firstPalindrome(vector<string>& words) {
        for (string &word : words) {
            if (isPalindrome(word))
                return word;
        }
        return ""; // No palindrome found
    }
};

//method-3
class Solution {
public:
    string firstPalindrome(vector<string>& words) {

        for (string &word : words) {     // Step 1: Loop through every string in the array
            int n = word.size();         // Step 2: Get the length of current word

            // Step 3: Check if word is palindrome using half comparison technique
            // Compare first half (beginning of string) 
            // with reversed second half (end of string backwards)
            if (equal(word.begin(), word.begin() + n / 2, word.rbegin())) {
                return word;             // ✅ If palindrome → return this string immediately
            }
        }
        return ""; // If no palindrome found in entire list, return empty string
    }
};


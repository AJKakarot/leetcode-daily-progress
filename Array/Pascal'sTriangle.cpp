#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Function to generate Pascal's Triangle up to numRows
    vector<vector<int>> generate(int numRows) {

        // Create a 2D vector (list of lists) to store the triangle
        vector<vector<int>> triangle(numRows);

        // Loop through each row
        for (int row = 0; row < numRows; row++) {

            // Step 1: Initialize current row with '1's
            // Row size = row index + 1
            triangle[row] = vector<int>(row + 1, 1);

            // Step 2: Fill the middle values using Pascal’s Rule
            // Skip first and last column (they are always 1)
            for (int col = 1; col < row; col++) {
                triangle[row][col] = triangle[row - 1][col - 1] + triangle[row - 1][col];
            }
        }

        return triangle;  // Return the completed triangle
    }
};

// Example usage
int main() {
    Solution obj;
    int numRows = 5;

    vector<vector<int>> result = obj.generate(numRows);

    // Print Pascal's Triangle
    cout << "Pascal's Triangle with " << numRows << " rows:" << endl;
    for (const auto& row : result) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}

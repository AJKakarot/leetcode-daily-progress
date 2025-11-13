#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Step 1: Get the number of rows (m) and columns (n)
        int m = matrix.size();
        int n = matrix[0].size();

        // Step 2: Treat the 2D matrix as a sorted 1D array
        //          with indices from 0 to m*n - 1
        int start = 0;
        int end = m * n - 1;

        // Step 3: Apply Binary Search
        while (start <= end) {
            int mid = start + (end - start) / 2;

            // Step 4: Convert the 1D mid index into 2D indices (row, col)
            int row = mid / n; // row index in matrix
            int col = mid % n; // column index in matrix

            // Step 5: Compare the middle element with target
            if (matrix[row][col] == target) {
                // Element found
                return true;
            } else if (matrix[row][col] < target) {
                // Move to the right half (larger elements)
                start = mid + 1;
            } else {
                // Move to the left half (smaller elements)
                end = mid - 1;
            }
        }

        // Step 6: Target not found
        return false;
    }
};

//approach-1 
#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();        // Number of rows
        int n = matrix[0].size();     // Number of columns

        // Step 1: Create a copy (temporary matrix) to mark where zeros occur
        vector<vector<int>> temp = matrix;

        // Step 2: Traverse the matrix to find zeros
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                // If the current element is 0, set its row and column to 0 in temp
                if (matrix[i][j] == 0) {
                    // Set entire row i to 0
                    for (int k = 0; k < n; k++) {
                        temp[i][k] = 0;
                    }

                    // Set entire column j to 0
                    for (int k = 0; k < m; k++) {
                        temp[k][j] = 0;
                    }
                }
            }
        }

        // Step 3: Copy the modified temp matrix back to the original
        matrix = temp;
    }
};


//approach-2

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();        // Number of rows
        int n = matrix[0].size();     // Number of columns

        // Step 1: Create marker arrays to track which rows and columns need to be zeroed
        vector<bool> row(m, false);
        vector<bool> col(n, false);

        // Step 2: Mark rows and columns that contain a zero
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    row[i] = true;
                    col[j] = true;
                }
            }
        }

        // Step 3: Update the matrix based on the markers
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (row[i] == true || col[j] == true) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
//Approach-3

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();        // number of rows
        int n = matrix[0].size();     // number of columns

        bool firstRowImpacted = false;
        bool firstColImpacted = false;

        // Step 1: Check if the first row has any zero
        for (int col = 0; col < n; col++) {
            if (matrix[0][col] == 0) {
                firstRowImpacted = true;
            }
        }

        // Step 2: Check if the first column has any zero
        for (int row = 0; row < m; row++) {
            if (matrix[row][0] == 0) {
                firstColImpacted = true;
            }
        }

        // Step 3: Use first row and column as markers
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;   // mark that entire row i should be zero
                    matrix[0][j] = 0;   // mark that entire column j should be zero
                }
            }
        }

        // Step 4: Set zeros based on markers
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Step 5: Handle first row separately if it was impacted
        if (firstRowImpacted) {
            for (int j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
        }

        // Step 6: Handle first column separately if it was impacted
        if (firstColImpacted) {
            for (int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};
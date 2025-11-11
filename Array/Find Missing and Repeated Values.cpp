#include <iostream>
#include <vector>
using namespace std;



class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        // Step 1: Find size of the grid
        int n = grid.size(); // if grid = [[1,3],[2,2]], then n = 2

        // Step 2: Total numbers from 1 to n²
        long long N = 1LL * n * n; // 1LL ensures multiplication is done in long
                                   // long (to prevent overflow)

        // Step 3: Initialize variables to hold actual sum and actual sum of
        // squares from the grid
        long long actualSum = 0;   // sum of all elements present in the grid
        long long actualSqSum = 0; // sum of squares of all elements

        // Step 4: Loop through the grid to compute both sums
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                long long val =
                    grid[i][j];   // extract the value at position (i, j)
                actualSum += val; // add it to the total sum
                actualSqSum +=
                    val * val; // add its square to the total square sum
            }
        }

        // Step 5: Compute expected sum and expected square sum for numbers 1..N
        // Formula for sum of first N natural numbers: N*(N+1)/2
        long long expectedSum = (N * (N + 1)) / 2;

        // Formula for sum of squares of first N natural numbers:
        // N*(N+1)*(2N+1)/6
        long long expectedSqSum = (N * (N + 1) * (2 * N + 1)) / 6;

        // Step 6: Calculate the difference between actual and expected values
        long long sumDiff = actualSum - expectedSum;    // = (a - b)
        long long sqDiff = actualSqSum - expectedSqSum; // = (a² - b²)

        // Step 7: Simplify second equation:
        // a² - b² = (a - b)(a + b)
        // => a + b = (sqDiff / sumDiff)
        long long sumAB = sqDiff / sumDiff; // (a + b)

        // Step 8: Solve the two equations:
        // a - b = sumDiff
        // a + b = sumAB
        // Add both equations: 2a = sumAB + sumDiff
        int a = (sumAB + sumDiff) / 2; // Repeated number (a)

        // Subtract to find b: b = a - (a - b) = a - sumDiff
        int b = a - sumDiff; // Missing number (b)

        // Step 9: Return the result as {repeated, missing}
        return {a, b};
    }
};

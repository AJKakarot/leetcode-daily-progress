#include <vector>
#include <numeric>

class Solution
{
public:
    int diagonalSum(std::vector<std::vector<int>> &mat)
    {
        int row = 0;

        auto lambda = [&](int sum, const std::vector<int> &vec) -> int
        {
            // Add primary diagonal: mat[row][row]
            sum += vec[row];

            // Add secondary diagonal: mat[row][n - row - 1], avoid double count
            if (row != vec.size() - row - 1)
            {
                sum += vec[vec.size() - row - 1];
            }

            row++; // Move to next row
            return sum;
        };

        int result = std::accumulate(mat.begin(), mat.end(), 0, lambda);
        return result;
    }
};

// method-2

class Solution
{
public:
    int diagonalSum(std::vector<std::vector<int>> &mat)
    {
        int n = mat.size();
        int sum = 0;

        for (int i = 0; i < n; i++)
        {
            sum += mat[i][i]; // Primary diagonal
            if (i != n - i - 1)
            {
                sum += mat[i][n - i - 1]; // Secondary diagonal (avoid double count)
            }
        }
        return sum;
    }
};

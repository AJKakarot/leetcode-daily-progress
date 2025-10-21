#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    // Function to create leftMax[] array
    // leftMax[i] = maximum height from index 0 to i
    vector<int> getLeftMax(vector<int>& height, int n) {
        vector<int> leftMax(n);
        leftMax[0] = height[0]; // First element has no left side, so it remains same

        for(int i = 1; i < n; i++) {
            // Compare current bar with previous maximum on the left
            leftMax[i] = max(leftMax[i - 1], height[i]);
        }
        return leftMax;
    }

    // Function to create rightMax[] array
    // rightMax[i] = maximum height from index i to last index
    vector<int> getRightMax(vector<int>& height, int n) {
        vector<int> rightMax(n);
        rightMax[n - 1] = height[n - 1]; // Last element has no right side

        for(int i = n - 2; i >= 0; i--) {
            // Compare current bar with next maximum on the right
            rightMax[i] = max(rightMax[i + 1], height[i]);
        }
        return rightMax;
    }

    // Main function to calculate trapped water
    int trap(vector<int>& height) {
        int n = height.size();

        // If size is 0 or 1, no water can be trapped
        if(n == 0 || n == 1) {
            return 0;
        }

        // Build leftMax and rightMax arrays
        vector<int> leftMax = getLeftMax(height, n);
        vector<int> rightMax = getRightMax(height, n);

        int totalWater = 0;

        // Calculate trapped water at each index
        for(int i = 0; i < n; i++) {
            // Water at position i = minimum of left and right wall - height[i]
            totalWater += min(leftMax[i], rightMax[i]) - height[i];
        }

        return totalWater;
    }
};

int main() {
    Solution obj;

    vector<int> height = {3, 0, 2, 0, 4}; // Example input
    cout << "Total trapped rainwater: " << obj.trap(height) << " units" << endl;

    return 0;
}

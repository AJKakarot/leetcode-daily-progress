#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buyPrice = prices[0];  // Minimum price seen so far (best buying day)
        int profit = 0;            // Maximum profit found so far

        // Traverse through the price list starting from day 1
        for (int i = 1; i < n; i++) {

            // If today's price is lower, update buyPrice
            if (prices[i] < buyPrice) {
                buyPrice = prices[i];
            } 
            // Otherwise, check the profit if we sell today
            else {
                int currProfit = prices[i] - buyPrice;
                profit = max(profit, currProfit);  // Keep the maximum profit
            }
        }

        return profit;  // Return the best possible profit
    }
};

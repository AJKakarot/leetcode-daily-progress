#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>> &matches) {
        unordered_map<int, int> lossCount; // To count how many times a player has lost

        // Step 1: Count losses for each player
        for (auto &match : matches) {
            int loser = match[1];
            lossCount[loser]++; // Increase loss count for the loser
        }

        vector<int> noLoss;      // Players who never lost
        vector<int> lostOnce;    // Players who lost exactly once

        // Step 2: Go through all matches again
        for (auto &match : matches) {
            int winner = match[0];
            int loser = match[1];

            // If winner is not present in lossCount → they never lost
            if (lossCount.find(winner) == lossCount.end()) {
                lossCount[winner] = 0; // So it doesn't get added multiple times
                noLoss.push_back(winner);
            }
        }

        // Step 3: Find players who lost exactly once
        for (auto &entry : lossCount) {
            if (entry.second == 1) {
                lostOnce.push_back(entry.first);
            }
        }

        // Step 4: Sort both lists
        sort(noLoss.begin(), noLoss.end());
        sort(lostOnce.begin(), lostOnce.end());

        return {noLoss, lostOnce};
    }
};

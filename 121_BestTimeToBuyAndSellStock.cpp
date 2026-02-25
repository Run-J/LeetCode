// Solution 1: Brute Force
// Logic:
// Try every pair (buy day i, sell day j where j > i)
// Compute prices[j] - prices[i] and track the maximum profit
// Time Complexity: O(N^2)
// Space Complexity: O(1)


// Solution 2: Optimal (Greedy / One Pass)
// Logic:
// - Keep track of the minimum price seen so far (best day to buy).
// - For each day, treat it as a potential selling day.
// - The profit for selling today = current price - minimum price so far.
// - Update the maximum profit accordingly.
//
// Why it works:
// At each step, we ensure we buy at the lowest possible price
// before selling at the current price.
//
// Time Complexity: O(N)
// Space Complexity: O(1)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;  // Minimum price seen so far (best buy price)
        int profit = 0;          // Maximum profit so far

        for (int i = 0; i < prices.size(); i++) {
            // If we sell today, what profit would we make?
            profit = max(profit, prices[i] - minPrice);

            // Update the minimum price for future days
            minPrice = min(minPrice, prices[i]);
        }

        return profit;
    }
};

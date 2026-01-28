// Solution 1: Greedy
// This greedy solution works because, with unlimited transactions allowed, 
// any continuous increase can be decomposed into daily profits without affecting the total gain.

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;

        // Traverse prices from day 1 to the end
        for (int i = 1; i < prices.size(); i++) {

            // If today's price is higher than yesterday's,
            // we take the profit of this upward movement
            if (prices[i] > prices[i - 1]) {
                profit += prices[i] - prices[i - 1];
            }
        }

        return profit;
    }
};

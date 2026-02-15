class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int max_profit = 0;

        // Start from the second day (index 1)
        for (size_t i = 1; i < prices.size(); ++i) {
            // If today's price is higher than yesterday's, we capture the profit
            if (prices[i] > prices[i - 1]) {
                max_profit += prices[i] - prices[i - 1];
            }
        }

        return max_profit; 
    }
};
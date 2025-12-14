class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        
        if (prices.empty()) {
            return 0;
        }

        int min_price = prices[0];
        int max_profit = 0;
        
        for (int i = 1; i < prices.size(); ++i) {
            
            // 1. Check if the current price is a new low (best day to buy)
            if (prices[i] < min_price) {
                min_price = prices[i];
            } 
            // 2. Otherwise, calculate profit if we sell today
            else {
                int current_profit = prices[i] - min_price;
                
                // Update the overall maximum profit
                if (current_profit > max_profit) {
                    max_profit = current_profit;
                }
            }
        }
        
        return max_profit;
    }
};
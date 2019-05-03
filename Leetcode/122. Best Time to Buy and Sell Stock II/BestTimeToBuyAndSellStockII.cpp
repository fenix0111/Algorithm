// Leetcode 122. Best Time to Buy and Sell Stock II
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
// Runtime: 8ms

// you are able to sell and then buy at the same day.
class Solution 
{
public:    
    int maxProfit(vector<int>& prices) 
    {
        int max = 0;
        
        if (prices.size() <= 1) {
            return max;
        }
        
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i - 1]) {
               max += prices[i] - prices[i - 1]; 
            }
        }
    
        return max;
    }
};

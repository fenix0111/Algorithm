// Leetcode 121. Best Time to Buy and Sell Stock
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
// Runtime: 4ms

// updated
// using dynamic programming, MAX = max(...max(max(prices(i), prices(i-1)) - prices(i-2)).. - prices(0))
class Solution {
public:
    int max(int x, int y) {
        if (x > y)
            return x;
        else 
            return y;
    }
    
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) {
            return 0;
        }
        int res = 0;
        int len = prices.size();
        int tmpmax = max(prices[len - 1], prices[len - 2]);
        for (int i = len - 2; i >= 0; i--) {
            tmpmax = max(prices[i], tmpmax);
            int diff = tmpmax - prices[i];
            if (diff > 0 && diff > res) {
                res = diff;
            } 
        }
        
        return res;
    }
};

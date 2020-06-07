// Leetcode 518. Coin Change 2
// https://leetcode.com/problems/coin-change-2/
// time complexity: O(amount * size(coins))
// space complexity: O(amount)

class Solution 
{
public:    
    int change(int amount, vector<int>& coins) 
    {
        vector<int> tbl(amount + 1, 0);
        tbl[0] = 1;
        for (int i = 0; i < coins.size(); i++)
        {
            for (int j = coins[i]; j <= amount; j++)
            {
                tbl[j] += tbl[j - coins[i]];
            }
        }
        
        return tbl[amount];
    }
};

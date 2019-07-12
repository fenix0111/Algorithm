// Leetcode 441. Arranging Coins
// https://leetcode.com/problems/arranging-coins/
// Runtime: 8ms

// relatively slow..
class Solution 
{
public:
    int arrangeCoins(int n) 
    {
        unsigned long long max = 1;
        while ((max + max * max) >> 1 <= n)
        {
            max++;
        }
        
        max--;
        return (int)max;
    }
};

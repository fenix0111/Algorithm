// Leetcode 860. Lemonade Change
// https://leetcode.com/problems/lemonade-change/
// Runtime: 12ms

// this solution is not general one
class Solution 
{
public:
    bool lemonadeChange(vector<int>& bills) 
    {
        int denoms[3] = { 0 }; // 0 $5, 1 $10, 2 $20
        
        for (int bill : bills)
        {
            if (bill == 5)
            {
                denoms[0]++;
            }
            else if (bill == 10)
            {
                if (denoms[0] < 1)
                {
                    return false;
                }
                else
                {
                    denoms[0]--;
                    denoms[1]++;
                }
            }
            else
            {
                if (denoms[1] > 0 && denoms[0] > 0)
                {
                    denoms[0]--;
                    denoms[1]--;
                    denoms[2]++;
                    continue;
                }
                
                if (denoms[0] > 3)
                {
                    denoms[0] -= 3;
                    denoms[2]++;
                    continue;
                }
                
                if (denoms[0] < 3 || denoms[1] < 1)
                {
                    return false;
                }
            }
        }
        
        return true;
    }
};

// Leetcode 343. Integer Break
// https://leetcode.com/problems/integer-break/
// 
// 

class Solution 
{
public:
    int helper(int n, vector<int>& tbl)
    {
        if (tbl[n] != -1)
        {
            return tbl[n];
        }
        
        if (n == 1)
            return 1;
        
        int max = 0;
        for (int i = 1; i < n; i++)
        {
            if (i * (n - i) > max)
            {
                max = i * (n - i);
                tbl[n] = max;
            }
                
            int res = i * helper(n - i, tbl);
            if (res > max)
            {
                max = res;
                tbl[n] = res;
            } 
        }
        
        return max;
    }
    
    int integerBreak(int n) 
    {
        vector<int> tbl(n + 1, -1);
        return helper(n, tbl);
    }
};

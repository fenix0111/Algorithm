// Leetcode 1680. Concatenation of Consecutive Binary Numbers
// https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers/
// time complexity: O(n)
// space complexity: O(1)

class Solution 
{
public:
    int getWidth(int n)
    {
        int w = 0;
        while (n > 0)
        {
            n = n >> 1;
            w++;
        }
        
        return w;
    }
    
    int concatenatedBinary(int n) 
    {
        int result = 1;
        for (int i = 2; i <= n; i++)
        {
            int w = getWidth(i);
            result = (result * (long long)pow(2, w) + i) % 1000000007;
        }
    
        return result;
    }
};

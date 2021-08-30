// Leetcode 1798. Maximum Number of Consecutive Values You Can Make
// https://leetcode.com/problems/maximum-number-of-consecutive-values-you-can-make/
// time complexity: O(n)
// space complexity: O(n), although I used 40001 integers

class Solution 
{
public:
    int getMaximumConsecutive(vector<int>& coins) 
    {
        int buf[40001] = { 0 };
        for (int coin : coins)
        {
            buf[coin]++;
        }
        int result = 1;
        for (int i = 0; i <= 40000; i++)
        {
            if (buf[i] > 0 && i > result)
            {
                break;
            }
            
            while (buf[i] > 0)
            {
                buf[i]--;
                result += i;
            }
        }
        
        return result;
    }
};

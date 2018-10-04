// Leetcode 258. Add Digits
// https://leetcode.com/problems/add-digits/description/
// Runtime: 4ms

// next: solve this without any loop/recursion in O(1) runtime
class Solution 
{
public:
    int addDigits(int num) 
    {
        if (num < 10)
        {
            return num;
        }
        
        int ret = num;
        int n = num;
        while (ret >= 10)
        {
            ret = 0;
            while (n != 0)
            {
                ret += n % 10;
                n = n / 10;
            }
            n = ret;
        }
        
        return ret;
    }
};

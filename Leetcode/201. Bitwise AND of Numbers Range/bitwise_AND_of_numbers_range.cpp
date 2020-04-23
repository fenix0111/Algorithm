// Leetcode 201. Bitwise AND of Numbers Range
// https://leetcode.com/problems/bitwise-and-of-numbers-range/
// Runtime: 8 ms
// Memory: 6 MB

class Solution 
{
public:
    int rangeBitwiseAnd(int m, int n) 
    {
        if (m == 0)
        {
            return 0;
        }
        
        int result = m;
        int power = 1;
        
        int num = n;
        
        // calculate the "lower boundary" of number n, which is not greater than n
        while (num > 1)
        {
            num = num >> 1;
            power = power << 1;
        }

        // if m is greater than pow(2, power), then we must do bitwise-and with values between [m, n]
        if (m >= power)
        {
            for (unsigned int i = m; i <= n; i++)
            {
                result = result & i;
            }
            
            return result;
        }
        else
        {
            // if m and n located in either side of pow(2, power), just return zero;
            return 0;
        }
    }
};

// Leetcode 29. Divide Two Integers
// https://leetcode.com/problems/divide-two-integers/
// Runtime: --

// to be continued...

class Solution 
{
public:
    int divide(int dividend, int divisor) 
    {
        if (divisor == 0 || (dividend == INT_MIN && divisor == -1)) 
            return INT_MAX;
        
        long long lldividend = abs((long long)dividend);
        long long lldivisor = abs((long long)divisor);
        long long res = 0;
        
        int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
        
        if (lldivisor == 1) 
            return sign == 1 ? lldividend : -lldividend;
        
        while (lldividend >= lldivisor) 
        {
            long long t = lldivisor;
            long long p = 1;
            
            while (lldividend >= (t << 1)) 
            {
                t <<= 1;
                p <<= 1;
            }
            res += p;
            lldividend -= t;
        }
        return sign == 1 ? res : -res;
    }
};

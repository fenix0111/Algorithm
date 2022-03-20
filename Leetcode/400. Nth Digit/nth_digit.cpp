// Leetcode 400. Nth Digit
// https://leetcode.com/problems/nth-digit/

class Solution
{
public:
    int findNthDigit(int n)
    {
        if (n < 10)
        {
            return n;
        }
        
        int w = 1;
        
        unsigned long long limit = 9 * pow(10, w - 1) * w;
        while (limit <= n)
        {
            if (w == 1)
                limit = 10;
            else
                limit = 9 * pow(10, w - 1) * w;
            
            if (limit > n)
                break;
            
            n -= limit;
            w++;
        }

        int number = 0;
        number = pow(10, w - 1);
        number += (n / w);
        
        // the result is (n % w)th number from left
        // which equal to w - (n % w) from right
        int right = w - (n % w);
        
        for (int i = 1; i < right; i++)
        {
            number /= 10;
        }
        
        return number % 10;
    }
};

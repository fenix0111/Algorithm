// Leetcode 878. Nth Magical Number
// https://leetcode.com/problems/nth-magical-number/
// time complexity: O(logn)
// space complexity: O(1)

class Solution
{
public:
    int nthMagicalNumber(int n, int a, int b)
    {
        unsigned long long end = ULONG_MAX;
        unsigned long long beg = 0;
        unsigned long long mid;
        int result = 0; 
        int MOD = 1000000007;
        
        int g = a >= b ? a : b;
        int l = a < b ? a : b;
        int gcd = a;
        
        while (b > 0)
        {
            long tmp = gcd;
            gcd = b;
            b = tmp % gcd;
        }
        
        while (beg < end)
        {
            mid = beg + (end - beg) / 2;
            unsigned long long dg = mid / g;
            unsigned long long dl = mid / l;

            // duplication needed to be eliminated
            // ex, 4 is divided by both 2 and 4, would be counted twice. this is incorrect.
            unsigned long long dy = (g * l) / gcd;
            unsigned long long dx = mid / dy;
            
            unsigned long long sum = dg + dl - dx;
                        
            if (sum >= n)
            {
                end = mid;
            }
            else
            {
                beg = mid + 1;
            }
        }
        
        return beg % MOD;
    }
};

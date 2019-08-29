// Leetcode 397. Integer Replacement
// https://leetcode.com/problems/integer-replacement/
// Runtime: 4ms

class Solution {
public:
    long long helper(long long n)
    {
        if (n == 1)
        {
            return 1;
        }

        if (n % 2 == 0)
        {
            return helper(n >> 1) + 1;
        }
        else
        {
            long long plus = helper(n + 1) + 1;
            long long minus = helper(n - 1) + 1;
            return plus < minus ? plus : minus;
        }
    }
    
    int integerReplacement(int n) 
    {
        long long i = (long long)n;
        return helper(i) - 1;
    }
};

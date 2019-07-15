// Leetcode 476. Number Complement
// https://leetcode.com/problems/number-complement/
// Runtime: 0ms

class Solution 
{
public:
    int findComplement(int num) 
    {
        int n = num;
        int mask = 0;
        while (n > 0)
        {
            n >>= 1;
            mask <<= 1;
            mask |= 1;
        }
        
        return (~num) & mask;
    }
};

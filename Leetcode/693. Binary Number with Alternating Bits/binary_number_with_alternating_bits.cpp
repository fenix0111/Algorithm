// Leetcode 693. Binary Number with Alternating Bits
// https://leetcode.com/problems/binary-number-with-alternating-bits/
// Runtime: 0ms

class Solution 
{
public:
    bool hasAlternatingBits(int n) 
    {
        int num = n >> 1;
        int prev = n & 1;
        
        while (num > 0)
        {
            if (prev ^ (num & 1))
            {
                prev = num & 1;
                num = num >> 1;
            }
            else
            {
                return false;
            }
        }
        
        return true;
    }
};

// Leetcode 231. Power of Two
// https://leetcode.com/problems/power-of-two/description/
// Runtime: 4ms

class Solution 
{
public:
    bool isPowerOfTwo(int n) 
    {
        return n > 0 ? (n & (n - 1)) == 0 : false;
    }
};

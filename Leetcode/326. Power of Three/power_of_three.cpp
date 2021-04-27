// Leetcode 326. Power of Three
// https://leetcode.com/problems/power-of-three/
// time complexity: ??
// space complexity: O(1)

class Solution 
{
public:
    bool isPowerOfThree(int n) 
    {
        return fmod(log10(n) / log10(3), 1) == 0;
    }
};

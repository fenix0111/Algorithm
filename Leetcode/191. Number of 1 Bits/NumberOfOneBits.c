// Leetcode 191. Number of 1 Bits
// https://leetcode.com/problems/number-of-1-bits/description/
// Runtime: 3ms

int hammingWeight(uint32_t n) 
{
    int res = 0;
    int count = 32;
    uint32_t num = n;
    int mod;
    while (num)
    {
        mod = num % 2;
        if (mod == 1)
            res++;
        num = num / 2;
    }
    return res;
}

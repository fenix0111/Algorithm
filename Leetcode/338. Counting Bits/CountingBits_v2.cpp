// Leetcode 338. Counting Bits
// https://leetcode.com/problems/counting-bits/
// Runtime: 48ms

// it works, why...
class Solution 
{
public:
    vector<int> countBits(int num) 
    {
        vector<int> ret;
        ret.assign(num + 1, 0);
        for (int i = 1; i <= num; i++)
        {
            ret[i] = ret[(i - 1) & i] + 1;
        }
        
        return ret;
    }
};

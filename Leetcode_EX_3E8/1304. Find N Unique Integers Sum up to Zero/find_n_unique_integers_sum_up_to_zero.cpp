// Leetcode 1304. Find N Unique Integers Sum up to Zero
// https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/
// Runtime: 4 ms
// Memory: 6.4 MB

// ?????
class Solution 
{
public:
    vector<int> sumZero(int n) 
    {
        vector<int> ret;
        for (int i = 1; i <= n / 2; i++)
        {
            ret.push_back(i);
            ret.push_back(-i);
        }
        
        // in case of odd number
        if (n & 1)
        {
            ret.push_back(0);
        }
        
        return ret;
    }
};

// Leetcode 1018. Binary Prefix Divisible By 5
// https://leetcode.com/problems/binary-prefix-divisible-by-5/

class Solution
{
public:
    vector<bool> prefixesDivBy5(vector<int>& nums)
    {
        int sz = nums.size();
        vector<bool> result(sz, false);
        int x = 0;
        for (int i = 0; i < sz; i++)
        {
            x *= 2;
            x += nums[i];

            result[i] = (x % 5 == 0);
            
            x %= 5;
        }
        
        return result;
    }
};

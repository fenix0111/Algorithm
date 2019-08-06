// Leetcode 645. Set Mismatch
// https://leetcode.com/problems/set-mismatch/
// Runtime: 36ms

class Solution 
{
public:
    vector<int> findErrorNums(vector<int>& nums) 
    {
        int sz = nums.size();
        vector<int> ret(2, 0);
        bool *tbl = (bool*)malloc(sz + 1);
        for (int i = 1; i <= sz; i++)
        {
            tbl[i] = true;
        }
        
        for (int i : nums)
        {
            if (tbl[i])
                tbl[i] = false;
            else
                ret[0] = i;
        }
        
        for (int i = 1; i <= sz; i++)
        {
            if (tbl[i])
            {
                ret[1] = i;
                break;
            }
        }
        
        return ret;
    }
};

// Leetcode 303. Range Sum Query - Immutable
// https://leetcode.com/problems/range-sum-query-immutable/
// Runtime: 36ms

class NumArray 
{
private:
    int *tbl = NULL;
public:
    NumArray(vector<int> nums) 
    {
        int sz = nums.size();
        if (sz > 0)
        {
            tbl = (int*)malloc(sizeof(int) * sz);
            tbl[0] = nums[0];
            for (int i = 1; i < sz; i++)
            {
                tbl[i] = tbl[i - 1] + nums[i];
            }
        }
    }
    
    int sumRange(int i, int j) 
    {
        if (i == 0)
        {
            return tbl[j];
        }
        else
        {
            return tbl[j] - tbl[i - 1];
        }
    }
};

// Leetcode 532. K-diff Pairs in an Array
// https://leetcode.com/problems/k-diff-pairs-in-an-array/
// Runtime: 36ms

class Solution 
{
public:
    int findPairs(vector<int>& nums, int k) 
    {
        int ret = 0;
        sort(nums.begin(), nums.end());
        int beg = 0;
        int end = 1;
        map<int,int> tbl;
        while (beg < nums.size() && end < nums.size())
        {
            if (nums[end] - nums[beg] == k)
            {
                if (tbl.find(nums[beg]) == tbl.end())
                {
                    tbl.insert(make_pair(nums[beg], nums[end]));
                    ret++;
                }
                beg++;
                end++;
                
                continue;
            }
            
            if (nums[end] - nums[beg] < k)
            {
                end++;
                continue;
            }
            
            if (nums[end] - nums[beg] > k)
            {
                if (end - beg == 1)
                {
                    beg++;
                    end++;
                }
                else
                {
                    beg++;
                }
                continue;
            }
        }
        
        return ret;
    }
};

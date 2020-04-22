// Leetcode 560. Subarray Sum Equals K
// https://leetcode.com/problems/subarray-sum-equals-k/
// Runtime: 48 ms
// Memory: 12.2 MB

// contiguous subarray which sum is k means that sum[0..j] - sum[0..i] is equal to k 
// (here , j >= i)
// using map, record the sum[0..i] of each index in nums, 
// then find if there is an entry which key is (sum[0..i] - k)
class Solution 
{
public:
    int subarraySum(vector<int>& nums, int k) 
    {
        int sz = nums.size();
        int ret = 0;
        
        unordered_map<int, int> tbl;
        tbl.insert(make_pair(0, 1));
        int sum = 0;
        for (int i = 0; i < sz; i++)
        {
            sum += nums[i];
            int diff = sum - k;
            
            auto it = tbl.find(diff);
            if (it != tbl.end())
            {
                ret += it->second;
            }
            
            if (tbl.find(sum) == tbl.end())
            {
                tbl.insert(make_pair(sum, 1));
            }
            else
            {
                (tbl.find(sum))->second++;
            }
            
        }
        return ret;
    }
};


// Leetcode 1673. Find the Most Competitive Subsequence
// https://leetcode.com/problems/find-the-most-competitive-subsequence/
// time complexity: O(n) 
// space complexity: O(n)

class Solution 
{
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) 
    {
        vector<int> result;
        int sz = nums.size();
        for (int i = 0; i < sz; i++)
        {
            int remain = sz - i;
            int free_space = k - result.size();
            while (!result.empty() && remain > free_space && nums[i] < result.back())
            {
                result.pop_back();
                remain--;
            }

            if (result.size() < k)
            {
                result.push_back(nums[i]);
            }
        }
        
        return result;
    }
};

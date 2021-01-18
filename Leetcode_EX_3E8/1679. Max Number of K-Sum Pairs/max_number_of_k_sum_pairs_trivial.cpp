// Leetcode 1679. Max Number of K-Sum Pairs
// https://leetcode.com/problems/max-number-of-k-sum-pairs/
// time complexity: O(nlogn)
// space complexity: O(1)

// using two pointers
class Solution 
{
public:
    int maxOperations(vector<int>& nums, int k) 
    {
        int sz = nums.size();
        sort(nums.begin(), nums.end());
        int l = 0;
        int r = sz - 1;
        int result = 0;
        while (l < r)
        {
            int sum = nums[l] + nums[r];
            if (sum == k)
            {
                l++;
                r--;
                result++;
            }
            else if (sum < k)
            {
                l++;
            }
            else
            {
                r--;
            }
        }
        
        return result;
    }
};

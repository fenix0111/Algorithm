// Leetcode 976. Largest Perimeter Triangle
// https://leetcode.com/problems/largest-perimeter-triangle/

class Solution
{
public:
    int largestPerimeter(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        int sz = nums.size();
        
        for (int i = sz - 1; i > 1; i--)
        {
            int sum = nums[i - 1] + nums[i - 2];
            if (nums[i] < sum)
            {
                return sum + nums[i];
            }
        }
        
        return 0;
    }
};

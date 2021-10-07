// Leetcode 740. Delete and Earn
// https://leetcode.com/problems/delete-and-earn/
// time complexity: O(n)
// space complexity: O(n)

// similar to "house robber"
class Solution
{
public:
    int deleteAndEarn(vector<int>& nums)
    {
        vector<int> sum(10001, 0);
        for (int num : nums)
        {
            sum[num] += num;
        }

        int x = sum[0];
        int y = sum[1];
        for (int i = 2; i < sum.size(); i++)
        {
            int maxval = max(x + sum[i], y);
            x = y;
            y = maxval;
        }

        return y;
    }
};

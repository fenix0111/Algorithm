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
        vector<int> sum(20001, 0);
        for (int num : nums)
        {
            sum[num] += num;
        }

        int result = 0;
        vector<int> tbl(20001, 0);
        tbl[0] = sum[0];
        tbl[1] = sum[1];
        for (int i = 2; i < sum.size(); i++)
        {
            tbl[i] = max(tbl[i - 2] + sum[i], tbl[i - 1]);
        }

        return tbl.back();
    }
};

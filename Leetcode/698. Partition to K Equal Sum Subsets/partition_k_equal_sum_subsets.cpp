// Leetcode 698. Partition to K Equal Sum Subsets
// https://leetcode.com/problems/partition-to-k-equal-sum-subsets/
// time complexity: ??
// space complexity: O(n)

class Solution
{
public:
    bool helper(vector<int>& nums, int k, int target, int idx, vector<bool>& visited, int sum)
    {
        if (k == 1)
        {
            return true;
        }

        if (target == sum)
        {
            return helper(nums, k - 1, target, 0, visited, 0);
        }

        for (int i = idx; i < nums.size(); i++)
        {
            if (sum + nums[i] > target || visited[i])
            {
                continue;
            }
            visited[i] = true;
            if (helper(nums, k, target, i + 1, visited, sum + nums[i]))
            {
                return true;
            }
            visited[i] = false;
        }

        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if ((sum % k) != 0)
        {
            return false;
        }

        int target = sum / k;
        vector<bool> visited(nums.size(), false);

        return helper(nums, k, target, 0, visited, 0);
    }
};

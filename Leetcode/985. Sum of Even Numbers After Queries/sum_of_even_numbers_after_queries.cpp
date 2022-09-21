// Leetcode 985. Sum of Even Numbers After Queries
// https://leetcode.com/problems/sum-of-even-numbers-after-queries/
// time complexity: O(N)
// space complexity: O(N)

class Solution
{
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries)
    {
        int even_sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if ((nums[i] & 1) == 0)
            {
                even_sum += nums[i];
            }
        }
        
        vector<int> result;
        for (const vector<int>& q : queries)
        {
            int val = q[0];
            int idx = q[1];
            int n = nums[idx] + val;
            if (n % 2 == 0)
            {
                if ((nums[idx] & 1) == 0)
                {
                    even_sum += val;
                }
                else
                {
                    even_sum += n;
                }
            }
            else
            {
                if ((nums[idx] & 1) == 0)
                {
                    even_sum -= nums[idx];
                }
            }
            
            result.push_back(even_sum);
            nums[idx] = n;
        }
        
        return result;
    }
};

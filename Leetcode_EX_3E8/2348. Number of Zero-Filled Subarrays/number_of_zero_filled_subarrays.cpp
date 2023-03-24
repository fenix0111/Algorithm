// Leetcode 2348. Number of Zero-Filled Subarrays
// https://leetcode.com/problems/number-of-zero-filled-subarrays/description/

class Solution
{
public:
    long long zeroFilledSubarray(vector<int>& nums)
    {
        int left = 0;
        long long result = 0;
        int i = 0;
        while (i < nums.size())
        {
            if (nums[i] == 0)
            {
                left = i;
                while (i < nums.size() && nums[i] == 0)
                {
                    i++;
                }

                int length = i - left;
                result += countSubarrays(length);
                left = i;
                i++;
            }
            else
            {
                i++;
            }
        }

        if (nums.back() == 0)
        {
            result += countSubarrays(nums.size() - left);
        }
        
        return result;
    }

    long long countSubarrays(long long length)
    {
        if (length < 2)
        {
            return length;
        }

        return length + countSubarrays(length - 1);
    }
};

// Leetcode 922. Sort Array By Parity II
// https://leetcode.com/problems/sort-array-by-parity-ii/
// time complexity: O(n)
// space complexity: O(1)

class Solution
{
public:
    vector<int> sortArrayByParityII(vector<int>& nums)
    {
        int left = 0;
        int right = 1;
        int size = nums.size();
        while (left < size && right < size)
        {
            while (left < size && (nums[left] & 1) == 0)
            {
                left += 2;
            }

            while (right < size && (nums[right] & 1) == 1)
            {
                right += 2;
            }

            if (left < size && right < size)
            {
                int tmp = nums[left];
                nums[left] = nums[right];
                nums[right] = tmp;
            }

            left += 2;
            right += 2;
        }

        return nums;
    }
};

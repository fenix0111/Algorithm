// Leetcode 137. Single Number II
// https://leetcode.com/problems/single-number-ii/description/
// Runtime: 12ms

class Solution 
{
public:
    int singleNumber(vector<int>& nums) 
    {
        if (nums.size() == 1)
        {
            return nums.at(0);
        }
		
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 1; i = i + 3)
        {
            if (nums.at(i) != nums.at(i + 1))
            {
                return nums.at(i);
            }
        }

        return nums.at(nums.size() - 1);
    }
    
    // 快速解法 (摘自网络, 4 ~ 7ms)
    int singleNumber(vector<int> &nums) 
    {
        int a = 0, b = 0;
        for (int i : nums) 
        {
            b = (b ^ i) & ~a;
            a = (a ^ i) & ~b;
        }
        return b;
    }
    
};

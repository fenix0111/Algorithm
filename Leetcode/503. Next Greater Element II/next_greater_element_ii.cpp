// Leetcode 503. Next Greater Element II
// https://leetcode.com/problems/next-greater-element-ii/
// time complexity: O(n^2)
// space complexity: O(1)

// brute force solution but was accepted
// it shouldn't be
class Solution
{
public:
    vector<int> nextGreaterElements(vector<int>& nums)
    {
        int sz = nums.size();
        vector<int> result(sz, 0);
  
        for (int i = 0; i < sz; i++)
        {
            int j = 1;
            bool found = false;
            while (j < sz)
            {
                int val = nums[(i + j) % sz];
                if (val > nums[i])
                {
                    result[i] = val;
                    found = true;
                    break;
                }
                j++;
            }
            
            if (!found)
            {
                result[i] = -1;
            }
        }
        
        return result;
    }
};

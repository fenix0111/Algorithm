// Leetcode 287. Find the Duplicate Number
// https://leetcode.com/problems/find-the-duplicate-number/description/
// Runtime: 8ms

// used the extra space. need to figure out the solution with O(1) extra space.
class Solution 
{
public:
    int findDuplicate(vector<int>& nums) 
    {
        int len = nums.size();
        bool *bs = (bool*)malloc(sizeof(bool) * len);
        for (int i = 0; i < len; i++)
        {
            bs[i] = false;
        }
        
        for (int i = 0; i < nums.size(); i++)
        {
            if (bs[nums[i]] == true)
            {
                ret = nums[i];
                break;
            }
            else
            {
                bs[nums[i]] = true;
            }
        }
        
        return 0; // never reaches here
    }
};

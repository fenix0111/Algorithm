// Leetcode 1437. Check If All 1's Are at Least Length K Places Away
// https://leetcode.com/problems/check-if-all-1s-are-at-least-length-k-places-away/
// time complexity: O(n)
// space complexity: O(1)

class Solution 
{
public:
    bool kLengthApart(vector<int>& nums, int k) 
    {
        int found = -1;
        int j = 0;
        int sz = nums.size();
        while (j < sz && nums[j] == 0)
        {
            j++;
        }
        
        found = j;
        j++;
        
        for (int i = j; j < nums.size(); j++)
        {
            if (nums[j] == 1)
            {
                if (j - found - 1 < k)
                {
                    return false;
                }

                found = j;
            }
        }
        
        return true;
    }
};

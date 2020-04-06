// Leetcode 015. 3Sum
// https://leetcode.com/problems/3sum/
// Runtime: 164 ms
// Memory: 15.9 MB

class Solution {
public:    
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        vector<vector<int>> ret;
        int sz = nums.size();
        if (sz < 3)
        {
            return ret;
        }
        
        sort(nums.begin(), nums.end());
        
        int l = -1;
        int m = 1;
        int r = sz - 1;
        
        while (l < r)
        {
            l++;
            m = l + 1;
            r = sz - 1;
            while (m < r)
            {      
                if (nums[l] + nums[m] + nums[r] == 0)
                {                    
                    vector<int> triple;
                    triple.push_back(nums[l]);
                    triple.push_back(nums[m]);
                    triple.push_back(nums[r]);
                    ret.push_back(triple);
                    
                    while (m < r && nums[m] == triple[1])
                    {
                        m++;
                    }
                    
                    while (m < r && nums[r] == triple[2])
                    {
                        r--;
                    }
                }
                else if (nums[l] + nums[m] + nums[r] < 0)
                {
                    m++;
                }
                else
                {
                    r--;
                }
            }
            
            while (l < sz - 1 && nums[l] == nums[l + 1])
            {
                l++;
            }
        }
        
        return ret;
    }
};

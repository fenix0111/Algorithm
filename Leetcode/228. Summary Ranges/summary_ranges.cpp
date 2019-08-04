// Leetcode 228. Summary Ranges
// https://leetcode.com/problems/summary-ranges/
// Runtime: 4ms

class Solution 

public:
    vector<string> summaryRanges(vector<int>& nums) 
    {
        vector<string> ret;
        if (nums.size() < 1)
            return ret;
        
        vector<string> range;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i == 0)
            {
                range.push_back(to_string(nums[0]));
            }
            else
            {
                if (((long)nums[i] - (long)nums[i - 1]) == 1)
                {
                    range.push_back(to_string(nums[i]));
                }
                else
                {
                    if (range.size() > 1)
                    {
                        string s = range[0] + "->" + range[range.size() - 1];
                        ret.push_back(s);
                    }
                    else
                    {
                        ret.push_back(range[0]);
                    }
                    range.clear();
                    range.push_back(to_string(nums[i]));
                }
            }
        }
        
        if (range.size() > 1)
        {
            string s = range[0] + "->" + range[range.size() - 1];
            ret.push_back(s);
        }
        else
        {
            ret.push_back(range[0]);
        }
        
        return ret;
    }
};

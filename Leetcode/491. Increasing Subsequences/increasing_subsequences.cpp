// 491. Increasing Subsequences
// https://leetcode.com/problems/increasing-subsequences/
// time complexity: O(size of nums * pow(2, size of nums))
// space complexity: O(size of nums) --> do not count return array as auxiliary space

class Solution 
{
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) 
    {
        vector<vector<int>> ret;
        
        if (nums.size() == 0)
            return ret;
        
        unordered_set<int> visited;
        for (int i = 0; i < nums.size(); i++)
        {
            bool seenBefore = false;
            if (visited.find(nums[i]) != visited.end())
            {
                seenBefore = true;
            }
            
            int sz = ret.size();
            for (int j = 0; j < sz; j++)
            {
                vector<int>& v = ret[j];
                int vsz = v.size();
                if (seenBefore)
                {
                    if (v.back() == nums[i])
                    {
                        v.push_back(nums[i]);
                        
                        // in case of sequence like [1,1,1,1,1]
                        if (vsz == 1)
                        {
                            vector<int> newv;
                            newv.push_back(nums[i]);
                            ret.push_back(newv);
                        }         
                    }
                    else
                    {
                        if (v.back() < nums[i])
                        {
                            vector<int> newv(v);
                            newv.push_back(nums[i]);
                            ret.push_back(newv);
                        }
                    }
                }
                else
                {
                    if (v.back() <= nums[i])
                    {
                        vector<int> newv(v);
                        newv.push_back(nums[i]);
                        ret.push_back(newv);
                    }
                }
            }
            
            if (!seenBefore)
            {
                vector<int> newone(1, nums[i]);
                ret.push_back(newone);
                
                visited.insert(nums[i]);
            }
        }
        
        vector<vector<int>> result;
        
        for (vector<int> v : ret)
        {
            if (v.size() > 1)
            {
                result.push_back(v);
            }
        }
        
        return result;
    }
};

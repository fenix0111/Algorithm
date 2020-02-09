// Leetcode 398. Random Pick Index
// https://leetcode.com/problems/random-pick-index/
// Runtime: 180 ms
// Memory Usage: 40.6 MB

// slow and waste
class Solution 
{
    struct Index
    {
        int last;
        vector<int> indices;
    };
    
    unordered_map<int, Index> m;
    
public:
    Solution(vector<int>& nums) 
    {
        for (int i = 0; i < nums.size(); i++)
        {
            if (m.find(nums[i]) == m.end())
            {
                Index newIndex;
                newIndex.last = 0;
                newIndex.indices.push_back(i);
                m.insert(make_pair(nums[i], newIndex));
            }
            else
            {
                m.find(nums[i])->second.indices.push_back(i);;
            }
        }
    }
    
    int pick(int target) 
    {
        Index existed = m.find(target)->second;
        int lastIndex = existed.last;
        int ret = existed.indices[lastIndex];
        
        lastIndex++;
        if (lastIndex >= existed.indices.size())
        {
            lastIndex = 0;
        }
        
        m.find(target)->second.last = lastIndex;
        
        return ret;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */

// Leetcode 347. Top K Frequent Elements
// https://leetcode.com/problems/top-k-frequent-elements/
// Runtime: 20ms

// strange....

class Solution 
{
public:
    static bool comp_desc(unordered_map<int, int>::iterator i, unordered_map<int, int>::iterator j) 
    { 
        return (i->second > j->second); 
    }
    
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        unordered_map<int, int> counter;
        for (int i = 0; i < nums.size(); i++)
        {
            unordered_map<int, int>::iterator it = counter.find(nums[i]);
            if (it == counter.end())
            {
                counter.insert(pair<int, int>(nums[i], 1));
            }
            else
            {
                it->second = it->second + 1;
            }
        }
        
        // 迭代器应该不是这样使用的。。有点野蛮
        vector<unordered_map<int, int>::iterator> tas;
        tas.reserve(counter.size());
        for (unordered_map<int, int>::iterator it = counter.begin(); it != counter.end(); it++)
        {
            tas.push_back(it);
        }
        
        sort(tas.begin(), tas.end(), comp_desc);
        
        vector<int> ret;
        
        for (int i = 0; i < k; i++)
        {
            ret.push_back(tas[i]->first);
        }
        
        return ret;
    }
};

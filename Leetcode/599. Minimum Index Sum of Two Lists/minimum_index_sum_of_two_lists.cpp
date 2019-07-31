// Leetcode 599. Minimum Index Sum of Two Lists
// https://leetcode.com/problems/minimum-index-sum-of-two-lists/
// Runtime: 100ms

class Solution 
{
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) 
    {
        unordered_map<string, int> tbl_count; // slightly faster than map
        for (int i = 0; i < list1.size(); i++)
        {
            tbl_count.insert(make_pair(list1[i], i));
        }
        
        for (int i = 0; i < list2.size(); i++)
        {
            auto it = tbl_count.find(list2[i]);
            if (it != tbl_count.end())
            {
                // ensure the sum is less than zero
                it->second = -(it->second) - i - 1;
            }
        }
        
        int min = INT_MIN;
        string minstr = "";
        vector<string> ret;
        for (auto it = tbl_count.begin(); it != tbl_count.end(); it++)
        {
            if (it->second < 0 && it->second > min)
            {
                min = it->second;
                if (ret.size() > 0)
                    ret.clear();
            }
            
            // in case of multiple minimum sum
            if (it->second == min)
            {
                ret.push_back(it->first);
            }
        }
        
        return ret;
    }
};

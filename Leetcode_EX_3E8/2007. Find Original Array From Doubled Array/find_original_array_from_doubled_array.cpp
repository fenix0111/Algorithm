// Leetcode 2007. Find Original Array From Doubled Array
// https://leetcode.com/problems/find-original-array-from-doubled-array/
// time complexity: O(NlogN)
// space complexity: O(N)

class Solution
{
public:
    vector<int> findOriginalArray(vector<int>& changed)
    {
        if (changed.size() % 2 != 0)
        {
            return {};
        }
        
        vector<int> result;
        map<int, int> counts;
        for (int n : changed)
        {
            counts[n]++;
        }
        
        for (auto it = counts.begin(); it != counts.end(); it++)
        {
            if (it->second == 0)
            {
                continue;
            }
            
            while (it->second > 0)
            {
                int twice = it->first * 2;
                if (counts.count(twice))
                {
                    it->second--;
                    
                    if (counts[twice] == 0)
                    {
                        return {};
                    }
                    
                    counts[twice]--;
                    result.push_back(it->first);
                }
                else
                {
                    return {};
                }
            }
        }
        
        if (result.size() != changed.size() / 2)
        {
            return {};
        }
        
        return result;
    }
};

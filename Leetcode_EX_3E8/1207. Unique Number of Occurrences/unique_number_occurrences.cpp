// Leetcode 1207. Unique Number of Occurrences
// https://leetcode.com/problems/unique-number-of-occurrences/
// Runtime: 4 ms
// Memory: 9.3 MB

class Solution 
{
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> tbl;
        for (int i = 0; i < arr.size(); i++)
        {
            auto it = tbl.find(arr[i]);
            if (it == tbl.end())
            {
                tbl.insert(make_pair(arr[i], 1));
            }
            else
            {
                (it->second)++;
            }
        }
        
        vector<int> count(1000, 0);
        
        for (auto it = tbl.begin(); it != tbl.end(); it++)
        {
            if (count[it->second] == 1)
            {
                return false;
            }
            else
            {
                count[it->second]++;
            }
        }
        
        return true;
    }
};

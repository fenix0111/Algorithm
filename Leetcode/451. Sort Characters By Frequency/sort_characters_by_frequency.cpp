// Leetcode 451. Sort Characters By Frequency
// https://leetcode.com/problems/sort-characters-by-frequency/
// Runtime: 28ms

// trivial solution using two maps
class Solution 
{
public:
    string frequencySort(string s) 
    {
        unordered_map<char, int> tbl;
        map<int, vector<char>> m;
        
        for (char c : s)
        {
            if (tbl.find(c) == tbl.end())
            {
                tbl.insert(make_pair(c, 1));
            }
            else   
            {
                tbl.find(c)->second++;
            }
        }
        
        for (auto it = tbl.begin(); it != tbl.end(); it++)
        {
            int c = it->second;
            if (m.find(c) == m.end())
            {
                m.insert(make_pair(c, vector<char>()));
            }
            
            for (int i = 0; i < c; i++)
            {
                m.find(c)->second.push_back(it->first);
            }
        }
        
        string ret = "";
        // the map keeps the ascending order of key by default
        for (auto it = m.rbegin(); it != m.rend(); it++)
        {
            vector<char> cv = it->second;
            for (char c : cv)
            {
                ret.push_back(c);
            }
        }
        
        return ret;
    }
};

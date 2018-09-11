// Leetcode 187. Repeated DNA Sequences
// https://leetcode.com/problems/repeated-dna-sequences/description/
// Runtime: 36ms

// using unordered_map instead of map, speed up from 100ms+ to ~30ms
class Solution 
{
public:
    vector<string> findRepeatedDnaSequences(string s) 
    {
        vector<string> v;
        
        if (s.size() < 10)
            return v;
        
        unordered_map<string, int> m;
        for (int i = 0; i < s.size() - 9; i++)
        {
            string tmp = s.substr(i, 10);
            if (m.find(tmp) == m.end())
            {
                m.insert(make_pair(tmp, 1));
            }
            else
            {
                if (m.find(tmp)->second == 1)
                {
                    v.push_back(tmp);
                }
                
                (m.find(tmp)->second)++;
            }
        }
 
        return v;
    }
};

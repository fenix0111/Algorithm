// Leetcode 290. Word Pattern
// https://leetcode.com/problems/word-pattern/description/
// Runtime: 0ms

class Solution 
{
public:
    bool wordPattern(string pattern, string str) 
    {
        // split the str
        istringstream iss(str);
        vector<string> results(istream_iterator<string>{iss}, istream_iterator<string>());
        
        map<char, string> m;
        map<string, char> rm;
        
        if (pattern.size() != results.size())
        {
            return false;
        }
        
        // check pattern->str
        for (int i = 0; i < results.size(); i++)
        {
            if (m.find(pattern[i]) == m.end())
            {
                m.insert(make_pair(pattern[i], results[i]));
            }
            else
            {
                if (m[pattern[i]] != results[i])
                {
                    return false;
                }
            }
        }
        
        // check str->pattern
        for (int i = 0; i < results.size(); i++)
        {
            if (rm.find(results[i]) == rm.end())
            {
                rm.insert(make_pair(results[i], pattern[i]));
            }
            else
            {
                if (rm[results[i]] != pattern[i])
                {
                    return false;
                }
            }
        }

        return true;
    }
};

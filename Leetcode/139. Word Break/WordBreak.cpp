// Leetcode 139. Word Break
// https://leetcode.com/problems/word-break/
// Runtime: 20ms

// using dynamic programming
class Solution 
{
public:        
    bool wordBreak(string s, vector<string>& wordDict) 
    {   
        vector<bool> tbl;
        tbl.assign(s.size() + 1, false);
        tbl[0] = true;
        
        for (int i = 0; i < tbl.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (tbl[j] && find(wordDict.begin(), wordDict.end(), s.substr(j, i - j)) != wordDict.end())
                {
                    tbl[i] = true;
                    break;
                }
            }
        }
        
        return tbl.back();
    }
};

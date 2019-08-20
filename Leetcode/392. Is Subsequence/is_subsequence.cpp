// Leetcode 392. Is Subsequence
// https://leetcode.com/problems/is-subsequence/
// Runtime: 60ms (not fast)

class Solution 
{
public:
    bool isSubsequence(string s, string t) 
    {
        if (s.size() == 0)
            return true;  // why ? 
        
        int is = 0;
        int it = 0;
        while (it < t.size())
        {
            if (s[is] == t[it])
            {
                is++;
                if (is == s.size())
                {
                    return true;
                }
            }
            it++;
        }
        
        return false;
    }
};

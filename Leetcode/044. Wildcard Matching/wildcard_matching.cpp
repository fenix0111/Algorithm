// Leetcode 44. Wildcard Matching
// https://leetcode.com/problems/wildcard-matching/
// 
// 

class Solution 
{
public:
    bool isMatch(string s, string p) 
    {        
        vector<vector<int>> tbl(s.length() + 1, vector<int>(p.length() + 1, -1));
        return check(s, 0, p, 0, tbl);
    }
    
    bool check(string& s, int si, string& p, int pi, vector<vector<int>>& tbl)
    {
        if (si >= s.length() && pi >= p.length())
        {
            return true;
        }
        
        if (pi >= p.length() && si < s.length())
        {
            return false;
        }
        
        if (tbl[si][pi] != -1)
        {
            return tbl[si][pi];
        }
        
        if (p[pi] == '*')
        {
            if (si < s.length())
            {
                tbl[si + 1][pi] = check(s, si + 1, p, pi, tbl);
                tbl[si + 1][pi + 1] = check(s, si + 1, p, pi + 1, tbl);
                tbl[si][pi + 1] = check(s, si, p, pi + 1, tbl);
                return tbl[si + 1][pi] || tbl[si + 1][pi + 1] || tbl[si][pi + 1];
            }
            else
            {
                return check(s, si, p, pi + 1, tbl);
            }
        }
        
        if (s[si] == p[pi] || (p[pi] == '?' && si < s.length()))
        {
            return check(s, si + 1, p, pi + 1, tbl);
        }
        
        return false;
    }
};

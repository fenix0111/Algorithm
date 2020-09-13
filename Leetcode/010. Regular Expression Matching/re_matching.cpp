// Leetcode 10. Regular Expression Matching
// https://leetcode.com/problems/regular-expression-matching/
// time complexity: O(len(s) * len(p))
// space complexity: O(len(s) * len(p))

// special thanks: 
// https://github.com/zhedahht/CodingInterviewChinese2/blob/master/19_RegularExpressionsMatching/RegularExpressions.cpp

class Solution 
{
public:
    bool isMatch(string s, string p) 
    {        
        // when encounter '*', proceed 2 indices would cause overflow
        // allocate one more space will prevent overflow
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
        
        if (p[pi + 1] == '*')
        {
            if (s[si] == p[pi] || (p[pi] == '.' && si < s.length()))
            {
                tbl[si + 1][pi] = check(s, si + 1, p, pi, tbl);
                tbl[si + 1][pi + 2] = check(s, si + 1, p, pi + 2, tbl);
                tbl[si][pi + 2] = check(s, si, p, pi + 2, tbl);
                return tbl[si + 1][pi] || tbl[si + 1][pi + 2] || tbl[si][pi + 2];
            }
            else
            {
                return check(s, si, p, pi + 2, tbl);
            }
        }
        
        if (s[si] == p[pi] || (p[pi] == '.' && si < s.length()))
        {
            return check(s, si + 1, p, pi + 1, tbl);
        }
        
        return false;
    }
};

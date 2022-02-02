class Solution
{
public:
    int find(const string& s, int left, int right, vector<vector<int>>& tbl)
    {
        if (tbl[left][right] != 0)
        {
            return tbl[left][right];
        }
        
        if (left > right)
        {
            return 0;
        }
        
        if (left == right)
        {
            return 1;
        }
        
        int result;
        if (s[left] == s[right])
        {
            result = find(s, left + 1, right - 1, tbl) + 2;
        }
        else
        {
            result = max(find(s, left + 1, right, tbl), find(s, left, right - 1, tbl));
        }
        
        tbl[left][right] = result;
        
        return result;
    }
    
    int longestPalindromeSubseq(string s)
    {
        int len = s.length();
        vector<vector<int>> tbl(len, vector<int>(len, 0));
        
        return find(s, 0, len - 1, tbl);
    }
};

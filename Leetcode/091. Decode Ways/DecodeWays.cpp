// Leetcode 91. Decode Ways
// https://leetcode.com/problems/decode-ways/
// Runtime: 0ms

class Solution 
{
public:
    int numDecodings(string s) 
    {
        int sz = s.size();
        if (sz < 1)
        {
            return 0;
        }
        
        if (s[0] == '0')
        {
            return 0;
        }
        
        vector<unsigned long long> tbl;
        tbl.assign(sz + 1, 0);
        tbl[0] = 1;
        tbl[1] = 1;
        
        for (int i = 1; i < sz; i++)
        {
            if (is_valid(s.substr(i, 1)))
            {
                tbl[i + 1] = tbl[i];
            }
            else
            {
                tbl[i] = 0;
            }
            
            if (is_valid(s.substr(i - 1, 2)))
            {
                tbl[i + 1] = tbl[i] + tbl[i - 1];
            }
        }
        
        return (int)tbl[sz];
    }
    
    bool is_valid(string s)
    {
        if (s[0] == '0')
        {
            return false;
        }
        
        int si = stoi(s);
        if (si <= 26)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

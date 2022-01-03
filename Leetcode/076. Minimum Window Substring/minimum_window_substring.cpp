// Leetcode 76. Minimum Window Substring
// https://leetcode.com/problems/minimum-window-substring/
// S = len(s), T = len(t)
// time complexity: O(S x log(S - T))
// space complexity: O(S + T)

// using binary search
class Solution
{
public:
    void clearCount(vector<int>& tbl)
    {
        for (int i = 0; i < tbl.size(); i++)
        {
            tbl[i] = 0;
        }
    }
    
    bool isValid(const vector<int>& tbl, const vector<int>& t)
    {
        for (int i = 0; i < 128; i++)
        {
            if (t[i] > 0 && t[i] > tbl[i])
            {
                return false;
            }
        }
        
        return true;
    }
    
    string minWindow(string s, string t) 
    {
        vector<int> tbl(128, 0);
        vector<int> tcounts(128, 0);

        int slen = s.length();
        int tlen = t.length();
        for (int i = 0; i < tlen; i++)
        {
            tcounts[t[i]]++;
        }
        int beg = tlen;
        int end = slen;
        string result = "";
        int len = INT_MAX;
        int imin = 0;
        while (beg <= end)
        {                        
            int mid = beg + (end - beg) / 2;
            
            int i = 0;
            bool valid = false;
            clearCount(tbl);
            while (i + mid <= slen)
            {
                if (i == 0)
                {
                    for (int j = 0; j < mid; j++)
                    {
                        tbl[s[j]]++;
                    }
                }
                else
                {
                    tbl[s[i - 1]]--;
                    tbl[s[i + mid - 1]]++;
                }
                
                if (isValid(tbl, tcounts))
                {
                    if (mid < len)
                    {
                        imin = i;
                        len = mid;
                    }
                    
                    valid = true;
                    break;
                }
                
                i++;
            }
            
            if (valid)
            {
                end = mid - 1;
            }
            else
            {
                beg = mid + 1;
            }
        }
        
        if (len == INT_MAX)
        {
            return "";
        }
        
        return s.substr(imin, len);
    }
};

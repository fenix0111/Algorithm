// Leetcode 455. Assign Cookies
// https://leetcode.com/problems/assign-cookies/
// Runtime: 40ms

class Solution 
{
public:
    int findContentChildren(vector<int>& g, vector<int>& s) 
    {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int spos = 0;
        int ret = 0;
        for (int i = 0; i < g.size(); i++)
        {
            while (i < s.size() && spos < s.size())
            {
                if (s[spos++] >= g[i])
                {
                    ret++;
                    break;
                }
            }
        }
        
        return ret;
    }
};

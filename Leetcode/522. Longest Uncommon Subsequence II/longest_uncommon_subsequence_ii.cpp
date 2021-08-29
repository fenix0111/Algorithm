// Leetcode 522. Longest Uncommon Subsequence II
// https://leetcode.com/problems/longest-uncommon-subsequence-ii/
// time complexity: O(n * n * maxlen(str))
// space complexity: O(1)

class Solution 
{
public:
    int findLUSlength(vector<string>& strs) 
    {
        int result = -1;
        bool is_ucs = true;
        for (int i = 0; i < strs.size(); i++)
        {
            is_ucs = true;
            for (int j = 0; j < strs.size(); j++)
            {
                if (i != j)
                {
                    int x = strs[j].length();
                    int y = strs[i].length();
                    int m = 0;
                    int n = 0;
                    while (m < x && n < y)
                    {
                        if (strs[j][m] == strs[i][n])
                        {
                            n++;
                        }
                        m++;
                    }
                    
                    if (n == y)
                    {
                        is_ucs = false;
                        break;
                    }
                }
            }
            
            if (is_ucs)
            {
                result = max(result, (int)strs[i].length());
            }
        }
        
        return result;
    }
};

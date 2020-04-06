// Leetcode 3. Longest Substring Without Repeating Characters
// https://leetcode.com/problems/longest-substring-without-repeating-characters/
// Runtime: 20 ms
// Memory: 7.6 MB

class Solution 
{
public:
    int lengthOfLongestSubstring(string s) 
    {
        int *tbl = (int*)malloc(sizeof(int) * 128);  // table for saving index
        for (int i = 0; i < 128; i++)
        {
            tbl[i] = -1;
        }
        
        int l = 0;
        int r = 0;
        int max = 0;

        while (r < s.size())
        {
            if (tbl[s[r]] != -1)
            {
                int len_l = tbl[s[r]] - l + 1;
                int len_r = r - tbl[s[r]];
                int tmp_max = len_l > len_r ? len_l : len_r;
                
                int allrange = r - l;  // case like "abcda", need to check the whole range
                tmp_max = tmp_max > allrange ? tmp_max : allrange;
                
                if (tmp_max > max)
                {
                    max = tmp_max;
                }
                
                // clear the table before repeated character
                int end = tbl[s[r]];
                for (int i = l; i < end; i++)
                {
                    tbl[s[i]] = -1;
                }
                
                // move left index next to the repeated character directly
                l = tbl[s[r]] + 1;
                tbl[s[r]] = r;
                r++;
            }
            else
            {
                // save the index of current character
                tbl[s[r]] = r;
                r++;
            }
        }
        
        // final check (missed this often)
        if (r - l > max)
        {
            max = r - l;
        }
        
        return max;
    }
};

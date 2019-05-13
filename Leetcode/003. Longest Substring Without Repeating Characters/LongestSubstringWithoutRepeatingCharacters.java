// Leetcode 3. Longest Substring Without Repeating Characters
// https://leetcode.com/problems/longest-substring-without-repeating-characters/
// Runtime: 32 ms

class Solution 
{
public:
    int lengthOfLongestSubstring(string s) 
    {
        int sz = s.size();
        if (sz < 1)
        {
            return sz;
        }
        
        bool *tbl = (bool*)malloc(sizeof(bool) * 128);
        for (int i = 0; i < 128; i++)
        {
            tbl[i] = false;
        }
        
        int i = 0;
        int j = 1;
        
        int max = 1;
        tbl[s[0]] = true;
        while (i < sz && j < sz)
        {
            if (tbl[s[j]])
            {
                // found same
                for (int i = 0; i < 128; i++)
                {
                    tbl[i] = false;
                }
                
                if (j - i > max)
                {
                    max = j - i;
                }
                
                i++;
                tbl[s[i]] = true;
                j = i + 1;
            }
            else
            {
                tbl[s[j]] = true;
                j++;
            }
        }
        
        // final check
        if (j - i > max)
        {
            max = j - i;
        }
            
        return max;
    }
};

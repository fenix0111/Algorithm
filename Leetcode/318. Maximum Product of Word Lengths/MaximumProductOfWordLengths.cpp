// Leetcode 318. Maximum Product of Word Lengths
// https://leetcode.com/problems/maximum-product-of-word-lengths/
// Runtime: 44ms

class Solution 
{
public:
    int maxProduct(vector<string>& words) 
    {
        int sz = words.size();
        vector<int> tbl(sz, 0);
        for (int i = 0; i < sz; i++)
        {
            string s = words[i];
            for (int j = 0; j < s.size(); j++)
            {
                int offset = s[j] - 97;
                tbl[i] |= (1 << 26 - offset);
            }
        }
        ‬
        int ret = 0;
        for (int i = 0; i < sz - 1; i++)
        {
            for (int j = i + 1; j < sz; j++)
            {
                if ((tbl[i] & tbl[j]) == 0)
                {
                    int p = words[i].size() * words[j].size();
                    if (p > ret)
                        ret = p;
                }
            }
        }
        
        return ret;
    }
};

// Leetcode 771. Jewels and Stones
// https://leetcode.com/problems/jewels-and-stones/
// Runtime: 4ms

class Solution 
{
public:
    int numJewelsInStones(string J, string S) 
    {
        int tbl[128] = { 0 };
        for (int i = 0; i < S.size(); i++)
        {
            tbl[S[i]]++;
        }
        
        int count = 0;
        for (int i = 0; i < J.size(); i++)
        {
            count += tbl[J[i]];
        }
        
        return count;
    }
};

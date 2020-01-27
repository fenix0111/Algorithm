// Leetcode 667. Beautiful Arrangement II
// https://leetcode.com/problems/beautiful-arrangement-ii/
// Runtime: 24ms

class Solution 
{
public:    
    vector<int> constructArray(int n, int k) 
    {
        vector<int> ret;        
        
        int insert_before = k; // number of elements insert before k
        int begin = k + 1;  // number(s) which would be inserted before k
        int rest = begin + 1;  // number(s) which would be appended after k sequentially
        
        int c = 0;
        int i = 1;
        while (insert_before >= 0)
        {
            // insert in interleaved way
            if (c % 2 == 0)
            {
                ret.push_back(i);
                i++;
            }
            else
            {
                ret.push_back(begin);
                begin--;
            }
            insert_before--;
            c++;
        }
        
        while (rest <= n)
        {
            ret.push_back(rest);
            rest++;
        }
        
        return ret;
    }
};

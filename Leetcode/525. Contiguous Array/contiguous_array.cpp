// Leetcode 525. Contiguous Array
// https://leetcode.com/problems/contiguous-array/
// Runtime: 272 ms
// Memory: 82.8 MB

class Solution 
{
public:    
    int findMaxLength(vector<int>& nums) 
    {
        if (nums.size() < 2)
            return 0;
        
        int count = 0;
        int maxlen = 0;
        unordered_map<int, int> tbl;
        tbl.insert(make_pair(0, -1));
        for (int i = 0; i < nums.size(); i++)
        {
            int n = nums[i];
            if (n == 0)
            {
                count--;
            }
            else
            {
                count++;
            }
            
            auto it = tbl.find(count);
            if (it == tbl.end())
            {
                tbl.insert(make_pair(count, i));
            }
            else
            {
                int prev = it->second;
                if (i - prev > maxlen)
                {
                    maxlen = i - prev;
                }
            }
        }
        
        return maxlen;
    }
};

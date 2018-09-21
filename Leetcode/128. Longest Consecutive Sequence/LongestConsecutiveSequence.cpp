// Leetcode 128. Longest Consecutive Sequence
// https://leetcode.com/problems/longest-consecutive-sequence/description/
// Runtime: 4ms

// the time complexity of this solution is O(NlogN) because of sorting
class Solution 
{
public:
    int longestConsecutive(vector<int>& nums) 
    {
        int ret = 0;
        if (nums.size() == 0)
            return 0;
        
        vector<int> v(nums);
        sort(v.begin(), v.end());
        
        int tmp = 0;
        for (int i = 0; i < v.size() - 1; i++)
        {
            // in case of negative number
            if (abs(v[i + 1] - v[i]) == 1)
            {
                tmp++;
            }
            else if (v[i + 1] - v[i] == 0)
            {
                continue;
            }
            else
            {
                if (tmp > ret)
                {
                    ret = tmp;
                }
                tmp = 0;
            }
        }
        
        // do not forget this final comparison
        if (tmp > ret)
            ret = tmp;
        
        return ret + 1;
    }
};

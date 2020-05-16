// Leetcode 918. Maximum Sum Circular Subarray
// https://leetcode.com/problems/maximum-sum-circular-subarray/
// Runtime: 152 MB
// Memory: 40 MB

// thanks for this awesome solution
// https://leetcode.com/problems/maximum-sum-circular-subarray/discuss/178422/One-Pass

class Solution 
{
public:
    int maxSubarraySumCircular(vector<int>& A) 
    {
        int result = 0;
        int minsum = 0;
        int maxsum = 0;
        int _max = INT_MIN;
        int _min = INT_MAX;
        int sum = 0;
        
        for (int i : A)
        {
            sum += i;
            maxsum = max(maxsum + i, i);
            _max = max(_max, maxsum);
            minsum = min(minsum + i, i);
            _min = min(_min, minsum);
        }
        
        if (_max > 0)
        {
            result = max(_max, sum - _min);
        }
        else
        {
            result = _max;
        }
        
        return result;
    }
};

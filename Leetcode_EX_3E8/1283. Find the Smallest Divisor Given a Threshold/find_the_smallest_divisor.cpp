// 1283. Find the Smallest Divisor Given a Threshold
// https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/
// time complexity: O( #nums * log(threshold) )
// space complexity: O(1)

class Solution 
{
public:
    int smallestDivisor(vector<int>& nums, int threshold) 
    {
        int l = 1;
        int r = threshold;
        int m = 0;
        
        // find max num
        for (int num : nums)
        {
            if (num > r)
            {
                r = num;
            }
        }
        
        int result = INT_MAX;
        int sum = 0;
        
        for (int num : nums)
        {
            minsum += ceil(double(num) / double(threshold));
        }
        
        while (l <= r)
        {
            m = l + (r - l) / 2;
            sum = 0;
            for (int num : nums)
            {
                sum += ceil(double(num) / double(m));
            }
            
            if (sum <= threshold)
            {
                r = m - 1;
                if (m < result)
                {
                    result = m;
                }
            }
            else
            {
                l = m + 1;
            }
        }
        
        return result;
    }
};

// Leetcode 643. Maximum Average Subarray I
// https://leetcode.com/problems/maximum-average-subarray-i/
// Runtime: 164ms

class Solution 
{
public:
    double findMaxAverage(vector<int>& nums, int k) 
    {
        double ave = 0;
        double sum = 0;
        bool begin = true;
        int i = 0;
        while (i < k)
        {
            sum += nums[i];
            i++;
        }
        
        ave = sum / k;
        while (i < nums.size())
        {
            sum -= nums[i - k];
            sum += nums[i];
            
            if (sum / k > ave)
                ave = sum / k;
            
            i++;
        }
        
        return ave;
    }
};

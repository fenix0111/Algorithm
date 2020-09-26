// Leetcode 495. Teemo Attacking
// https://leetcode.com/problems/teemo-attacking/
// time complexity: O(size of timeSeries)
// space complexity: O(1)

class Solution 
{
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) 
    {
        if (timeSeries.size() == 0)
            return 0;
        
        int result = duration;
        int diff;
        for (int i = 1; i < timeSeries.size(); i++)
        {
            diff = timeSeries[i] - timeSeries[i - 1];
            if (diff < duration)
            {
                result += diff;
            }
            else
            {
                result += duration;
            }
        }
        
        return result;
    }
};

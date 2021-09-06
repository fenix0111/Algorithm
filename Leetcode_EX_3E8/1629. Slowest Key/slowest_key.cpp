// Leetcode 1629. Slowest Key
// https://leetcode.com/problems/slowest-key/
// time complexity: O(n)
// space complexity: O(1)

class Solution 
{
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) 
    {
        char result = keysPressed[0];
        int max_gap = releaseTimes[0];
        for (int i = 1; i < releaseTimes.size(); i++)
        {
            int gap = releaseTimes[i] - releaseTimes[i - 1];
            if (gap > max_gap)
            {
                max_gap = gap;
                result = keysPressed[i];
            }
            else if (gap == max_gap)
            {
                result = max(result, keysPressed[i]);
            }
        }
        
        return result;
    }
};

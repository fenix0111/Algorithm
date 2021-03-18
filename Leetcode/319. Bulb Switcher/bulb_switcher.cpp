// Leetcode 319. Bulb Switcher
// https://leetcode.com/problems/bulb-switcher/
// time complexity: O(logn)
// space complexity: O(1)

// the i-th bulb which "i" is perfect square will be turned on in the final state
class Solution 
{
public:
    int bulbSwitch(int n) 
    {
        int ret = 0;
        long long num = 1;
        while (num * num <= (long long)n)
        {
            num++;
            ret++;
        }
        
        return ret;
    }
};

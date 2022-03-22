// Leetcode 650. 2 Keys Keyboard
// https://leetcode.com/problems/2-keys-keyboard/
// 
// 

// trivial recursive solution
class Solution
{
    int result = INT_MAX;
public:
    void minSteps(int target, int steps, int current, int next, bool copied)
    {
        if (current == target)
        {
            result = min(result, steps);
            return;
        }
        
        if (next > target || current > target)
        {
            return;
        }
        
        if (copied)
        {
            // paste
            minSteps(target, steps + 1, current + next, next, false);
        }
        else
        {
            // copy
            minSteps(target, steps + 1, current, current, true);
            
            // paste
            minSteps(target, steps + 1, current + next, next, false);
        }
    }
    
    int minSteps(int n) 
    {
        if (n == 1)
            return 0;
        
        // must copy at first time
        minSteps(n, 1, 1, 1, true);
        
        return result;
    }
};

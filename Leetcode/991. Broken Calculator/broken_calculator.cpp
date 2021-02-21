// Leetcode 991. Broken Calculator
// https://leetcode.com/problems/broken-calculator/
// time complexity: O(logn)
// space complexity: O(1)

// from Y to X
class Solution 
{
public:
    int brokenCalc(int X, int Y) 
    {
        int step = 0;
        int x = X;
        int y = Y;
        while (x < y)
        {
            if (y % 2 == 0)
            {
                y >>= 1;
            }
            else
            {
                y += 1;
            }
           
            step++;
        }
        
        step += abs(x - y);
        
        return step;
    }
};

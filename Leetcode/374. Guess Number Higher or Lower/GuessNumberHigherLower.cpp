// Leetcode 374. Guess Number Higher or Lower
// https://leetcode.com/problems/guess-number-higher-or-lower/description/
// Runtime: 0ms

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

// using binary search
class Solution 
{
public:
    int guessNumber(int n) 
    {
        unsigned int low = 1;
        unsigned int high = n;
        unsigned int mid = (high + low) / 2;
        
        while (low < high)
        {
            if (guess(mid) == 1)
            {
                // lower
                low = mid + 1;
                mid = (high + low) / 2;
            }
            else if (guess(mid) == -1)
            {
                // higher
                high = mid - 1;
                mid = (high + low) / 2;
            }
            else
            {
                return mid;
            }
        }
        
        return mid;
    }
};

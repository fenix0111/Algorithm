// Leetcode 1551. Minimum Operations to Make Array Equal
// https://leetcode.com/problems/minimum-operations-to-make-array-equal/
// time complexity: O(n)
// space complexity: O(1)

// the average of the array is n
// what we need to do is making each arr[i] equal to the average
class Solution 
{
public:
    int minOperations(int n) 
    {
        int result = 0;
        int step = 0;
        int half = n >> 1;
        while (step < half)
        {
            result += (n - (2 * step + 1));
            step++;
        }
        
        return result;
    }
};

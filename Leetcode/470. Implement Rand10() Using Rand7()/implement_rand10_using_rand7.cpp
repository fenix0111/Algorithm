// Leetcode 470. Implement Rand10() Using Rand7()
// https://leetcode.com/problems/implement-rand10-using-rand7/

// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

// this solution works.. why...
class Solution 
{
public:
    int rand10() 
    {
        int sum = 0;
        int i = 10;
        while (i > 0)
        {
            sum += rand7();
            i--;
        }
        
        return sum % 10 + 1;
    }
};

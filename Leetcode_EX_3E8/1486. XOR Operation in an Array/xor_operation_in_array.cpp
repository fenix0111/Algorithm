// Leetcode 1486. XOR Operation in an Array
// https://leetcode.com/problems/xor-operation-in-an-array/
// time complexity: O(N)
// space complexity: O(1)

class Solution
{
public:
    int xorOperation(int n, int start)
    {
        int result = start;
        while (n > 1)
        {
            start += 2;
            result ^= start;
            n--;
        }
        
        return result;
    }
};

// Leetcode 421. Maximum XOR of Two Numbers in an Array
// https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/
// time complexity: O(n)
// space complexity: O(n)

class Solution
{
public:
    int findMaximumXOR(vector<int>& nums)
    {
        int result = 0;
        int mask = 0;
        for (int i = 31; i >= 0; i--)
        {
            mask |= (1 << i);
            unordered_set<int> buf;
            for (int num : nums)
            {
                buf.insert(num & mask);
            }
            
            int guess = result | (1 << i);
            for (int e : buf)
            {
                if (buf.count(e ^ guess))
                {
                    result = guess;
                }
            }
        }
        
        return result;
    }
};

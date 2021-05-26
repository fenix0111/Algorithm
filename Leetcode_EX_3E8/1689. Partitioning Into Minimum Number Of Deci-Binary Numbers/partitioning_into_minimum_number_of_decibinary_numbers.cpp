// Leetcode 1689. Partitioning Into Minimum Number Of Deci-Binary Numbers
// https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/
// time complexity: O(n)
// space complexity: O(1)

// oh come on...
class Solution 
{
public:
    int minPartitions(string n) 
    {
        char result = '0';
        for (char c : n)
        {
            if (c > result)
            {
                result = c;
            }
        }
        return result - '0';
    }
};

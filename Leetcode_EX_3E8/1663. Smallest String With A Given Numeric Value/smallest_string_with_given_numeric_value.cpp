// Leetcode 1663. Smallest String With A Given Numeric Value
// https://leetcode.com/problems/smallest-string-with-a-given-numeric-value/
// time complexity: O(n)
// space complexity: O(1) --> not included result string

// greedy solution
class Solution 
{
public:
    string getSmallestString(int n, int k) 
    {
        string result(n, 'a');
        int i = n - 1;
        int target = k - n;
        while (target > 0)
        {
            result[i] = 'z';
            target -= 25;
            i--;
        }
        
        if (target < 0)
        {
            result[i + 1] += target;
        }
        
        return result;
    }
};

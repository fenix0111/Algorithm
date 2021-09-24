// Leetcode 1137. N-th Tribonacci Number
// https://leetcode.com/problems/n-th-tribonacci-number/
// time complexity: O(n)
// space complexity: O(n)

class Solution 
{
public:
    int tribonacci(int n) 
    {
        vector<int> buf(38, 0);
        buf[0] = 0;
        buf[1] = 1;
        buf[2] = 1;
        
        if (n == 0 || n == 1 || n == 2) 
            return buf[n];
        
        for(int i = 3; i <= n; i++)
        {
            buf[i] = buf[i - 1] + buf[i - 2] + buf[i - 3];
        }
        
        return buf[n];
    }
};

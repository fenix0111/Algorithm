// Leetcode 202 Happy Number
// https://leetcode.com/problems/happy-number/
// Runtime: 0 ms
// Memory: 6.3 MB

class Solution 
{
public:
    bool isHappy(int n) 
    {
        unordered_set<int> seen;
        int num = n;
        while (num > 1 && seen.find(num) == seen.end())
        {
            seen.insert(num);
            num = square_sum(num);
        }
        
        return num == 1;
    }
    
    int square_sum(int n)
    {
        int num = n;
        int sum = 0;
        while (num)
        {
            int digit = num % 10;
            sum += digit * digit;
            num = num / 10;
        }
        
        return sum;
    }
};

// Leetcode 412. Fizz Buzz
// https://leetcode.com/problems/fizz-buzz/
// Runtime: 0ms

class Solution 
{
public:
    vector<string> fizzBuzz(int n) 
    {
        vector<string> ret;
        
        for (int i = 1; i <= n; i++)
        {
            if (i % 3 == 0 && i % 5 == 0)
            {
                ret.push_back("FizzBuzz");
                continue;
            }
            
            if (i % 3 == 0)
            {
                ret.push_back("Fizz");
                continue;
            }
            
            if(i % 5 == 0)
            {
                ret.push_back("Buzz");
                continue;
            }
            
            ret.push_back(to_string(i));
        }
        
        return ret;
    }
};

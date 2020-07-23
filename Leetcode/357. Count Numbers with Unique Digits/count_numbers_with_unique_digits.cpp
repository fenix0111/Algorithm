// Leetcode 357. Count Numbers with Unique Digits
// https://leetcode.com/problems/count-numbers-with-unique-digits/
// 
// 

// with one digits there are 10 cases;
// with two, most significant digit has 9 cases, the other has 9 cases because the zero coule be selected.
// with three, the last digit has 8 cases, total cases = 9 x 9 x 8 + 9 x 9 + 10
// so on

class Solution 
{
public:
    int countNumbersWithUniqueDigits(int n) 
    {
        if (n == 0)
            return 1;
        
        if (n == 1)
        {
            return 10;
        }
        
        int c = n;
        int count = 9;
        int total = 0;
        while (c > 0)
        {
            if (c == n)
            {
                total = 9;
            }
            else
            {
                total = total * count;
                count--;
            }
            c--;
        }
        
        return total + countNumbersWithUniqueDigits(n - 1);
    }
};

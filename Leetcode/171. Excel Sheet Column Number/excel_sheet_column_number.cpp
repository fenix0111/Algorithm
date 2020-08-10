// Leetcode 171. Excel Sheet Column Number
// https://leetcode.com/problems/excel-sheet-column-number/

class Solution 
{
public:
    int titleToNumber(string s) 
    {
        int number = 0;
        for (int i = 0; i < s.length(); i++)
        {
            number = number * 26 + (s[i] - 'A' + 1);
        }
        
        return number;
    }
};

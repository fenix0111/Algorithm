// Leetcode 1641. Count Sorted Vowel Strings
// https://leetcode.com/problems/count-sorted-vowel-strings/
// time complexity: O(n)
// space complexity: O(1)

class Solution 
{
public:
    int countVowelStrings(int n) 
    {
        if (n == 1)
        {
            return 5;
        }
        
        int result = 15;
        int tbl[5] = { 5, 4, 3, 2, 1 };
        int sum = 0;
        for (int i = 2; i <= n; i++)
        {
            int tmp0 = result;
            
            int tmp1 = result - tbl[0];
            result -= tbl[0];
            
            int tmp2 = result - tbl[1];
            result -= tbl[1];
            
            int tmp3 = result - tbl[2];
            result -= tbl[2];
            
            int tmp4 = result - tbl[3];
            result -= tbl[3];

            tbl[0] = tmp0;
            tbl[1] = tmp1;
            tbl[2] = tmp2;
            tbl[3] = tmp3;
            tbl[4] = tmp4;
            
            result = 0;
            for (int j = 0; j < 5; j++)
            {
                result += tbl[j];
            }
        }
        
        return tbl[0];
    }
};

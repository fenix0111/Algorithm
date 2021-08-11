// Leetcode 926. Flip String to Monotone Increasing
// https://leetcode.com/problems/flip-string-to-monotone-increasing/
// time complexity: O(n)
// space complexity: O(n)

class Solution 
{
public:
    int minFlipsMonoIncr(string s) 
    {
        int slen = s.length();

        vector<int> ones(slen, 0);
        vector<int> zeroes(slen, 0);
        
        int count_one = 0;
        int count_zero = 0;
        for (int i = 0; i < slen; i++)
        {
            if (s[i] == '1')
            {
                ones[i] = count_one;
                count_one++;
                zeroes[i] = count_zero;
            }
            else
            {
                ones[i] = count_one;
                zeroes[i] = count_zero;
                count_zero++;
            }
        }
        
        int result = min(count_one, count_zero);
        
        for (int i = 0; i < slen; i++)
        {
            int l0r1 = ones[i] + (count_zero - zeroes[i]);
            result = min(result, l0r1);
        }
        
        return result;
    }
};

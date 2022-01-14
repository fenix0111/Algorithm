// Leetcode 8. String to Integer (atoi)
// https://leetcode.com/problems/string-to-integer-atoi/description/Runtime: 15ms
// time complexity: O(n)
// space complexity: O(1)

class Solution
{
public:
    int myAtoi(string s)
    {
        int isMinus = -1;  // -1 for no sign
        int len = s.length();
        int result = 0;
        long long tmp = 0;
        int begin = 0;
        int end = -1;
        int actlen = 0;
        bool leadingZero = false;

        while (isspace(s[begin]))
        {
            begin++;
        }
        
	// ignore leading zeroes
        while (s[begin] == '0')
        {
            leadingZero = true;
            begin++;
        }

        // "00000-42a1234"
	// sign symbol cannot appear after numbers, even if they are zeroes
        if (s[begin] == '+')
        {
            if (leadingZero)
            {
                return 0;
            }
            isMinus = 0;
            begin++;
        }
        else if (s[begin] == '-')
        {
            if (leadingZero)
            {
                return 0;
            }
            isMinus = 1;
            begin++;
        }
        
	// "-000000000000001"
        while (s[begin] == '0')
        {
            begin++;
        }

        for (int i = begin; i < len; i++)
        {
            if (isdigit(s[i]))
            {
                end = i;
            }
            else
            {
                break;
            }
        }

        actlen = end - begin + 1;

        if (actlen == 0)
        {
            return 0;
        }

        if (actlen > 10)
        {
            if (isMinus == 1)
            {
                return INT_MIN;
            }
            else
            {
                return INT_MAX;
            }
        }

        for (int j = 0; j < actlen; j++)
        {
            tmp += pow(10, actlen - j - 1) * (s[begin + j] - 48);
        }

        if (isMinus == 1)
        {
            tmp = -tmp;
        }

        if (tmp > INT_MAX)
        {
            result = INT_MAX;
        }
        else if (tmp < INT_MIN)
        {
            result = INT_MIN;
        }
        else
        {
            result = tmp;
        }
        return result;
    }
};

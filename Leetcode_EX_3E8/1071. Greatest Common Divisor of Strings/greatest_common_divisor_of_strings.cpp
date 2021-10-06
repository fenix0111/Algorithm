// Leetcode 1071. Greatest Common Divisor of Strings
// https://leetcode.com/problems/greatest-common-divisor-of-strings/
// time complexity: O(max(len(str1), len(str2)))
// space complexity: O(len(str1) + len(str2))

// imitated original gcd algorithm
class Solution
{
public:
    string gcdOfStrings(string str1, string str2)
    {
        string x = str1;
        string y = str2;

        while (true)
        {
            if (x.compare(y) == 0)
            {
                break;
            }
            
            if (x.length() < y.length())
            {
                string tmp = x;
                x = y;
                y = tmp;
            }

            int ix = x.length() - 1;
            int iy = y.length() - 1;
            while (iy >= 0)
            {
                if (x[ix] != y[iy])
                {
                    return "";
                }
                ix--;
                iy--;
            }

            x = x.substr(0, ix + 1);
        }

        return x;
    }
};

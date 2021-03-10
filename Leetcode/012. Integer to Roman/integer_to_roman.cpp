// Leetcode 12. Integer to Roman
// https://leetcode.com/problems/integer-to-roman/description/
// time complexity: O(n)
// space complexity: O(1)

class Solution 
{
public:
    string intToRoman(int num) 
    {
        int decimal = num;
        string res = "";

        string ht = "";
        string hh = "";
        string hd = "";
        string hs = "";

        string at[4] = {"", "M", "MM", "MMM"};
        string ah[10] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        string ad[10] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        string as[10] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};

        int mod = 1;
        int pos = 0;
        int overalllen = 0;

        while (decimal)
        {
            mod = decimal % 10;
            decimal = decimal / 10;
            pos++;
            switch(pos)
            {
                case 1:
                {
                    int len = as[mod].length();
                    hs += as[mod];
                    overalllen += len;
                    break;
                }
                case 2:
                {
                    int len = ad[mod].length();
                    hd += ad[mod];
                    overalllen += len;

                    break;
                }
                case 3:
                {
                    int len = ah[mod].length();
                    hh += ah[mod];
                    overalllen += len;
                    break;
                }
                case 4:
                {
                    int len = at[mod].length();
                    ht += at[mod];
                    overalllen += len;
                    break;
                }
                default:
                {
                    break;
                }
            }
        }

        if(!ht.empty())
            res += ht;
        
        if (!hh.empty())
            res += hh;

        if (!hd.empty())
            res += hd;

        if (!hs.empty())
            res += hs;

        return res;
    }
};

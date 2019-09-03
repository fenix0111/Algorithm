// Leetcode 166. Fraction to Recurring Decimal
// https://leetcode.com/problems/fraction-to-recurring-decimal/
// Runtime: 0ms

// code is a bit messy..
// be careful of integer overflow
class Solution 
{
public:
    string fractionToDecimal(int numerator, int denominator) 
    {
        if (numerator == 0)
        {
            return "0";
        }
        
        string ret = "";
        if ((numerator < 0 && denominator > 0) ||(numerator > 0 && denominator < 0))
        {
            // result should be negative
            ret += "-";
        }
        
        unordered_set<long long> seen_before;
        unordered_map<long long, long long> tbl;  // record numerator and index of fraction
        
        vector<long long> decimals;
        vector<long long> fracs;
        
        long long n = (long long)abs((long long)numerator);
        long long d = (long long)abs((long long)denominator);
        bool is_frac = false;
        bool has_repeat = false;
        int pos = 0;  // begin repeat
        while (n != 0)
        {
            if (seen_before.find(n) != seen_before.end())
            {
                has_repeat = true;
                if (tbl.find(n) != tbl.end())
                    pos = tbl.find(n)->second;
                break;
            }
            seen_before.insert(n);
            long long quotient = n / d;
            
            if (is_frac)
            {
                tbl.insert(make_pair(n, fracs.size()));
                fracs.push_back(quotient);
            }
            else
            {
                decimals.push_back(quotient);
            }
            
            is_frac = true;
            n = n - d * quotient;
            n = n * 10;
        }
        
        for (int i = 0; i < decimals.size(); i++)
        {
            ret.append(to_string(decimals[i]));
        }
                
        if (fracs.size() == 0)
        {
            return ret;  // no fracs
        }
        else
        {
            ret.append(".");
            if (has_repeat)
            {
                for (int i = 0; i < fracs.size(); i++)
                {
                    if (i == pos)
                    {
                        ret.append("(");
                    }
                    ret.append(to_string(fracs[i]));
                }
                ret.append(")");
            }
            else
            {
                for (int i = 0; i < fracs.size(); i++)
                {
                    ret.append(to_string(fracs[i]));
                }
            }
        }
        
        return ret;
    }
};

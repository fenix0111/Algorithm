// Leetcode 816. Ambiguous Coordinates
// https://leetcode.com/problems/ambiguous-coordinates/
// time complexity: 
// space complexity: 

class Solution 
{
public:
    bool isValid(string& integer, string& fraction)
    {        
        if (integer.empty() || (integer.length() > 1 && integer[0] == '0'))
        {
            return false;
        }
        
        if (!fraction.empty())
        {
            int num = stoi(fraction);
            
            // eliminate string like "0000000" and trailing zeroes
            if (fraction.length() > 0 && num == 0)
            {
                return false;
            }
            
            if (fraction.length() > 0 && fraction.back() == '0')
            {
                return false;
            }
        }
        
        return true;
    }
    
    vector<string> ambiguousCoordinates(string s) 
    {
        vector<string> result;
        
        // get rid of the parentheses
        string ss = s.substr(1, s.length() - 2);

        for (int i = 1; i < ss.length(); i++)
        {
            string left = ss.substr(0, i);
            string right = ss.substr(i, ss.length() - i);
            
            for (int l = 0; l <= left.length(); l++)
            {
                string lleft = left.substr(0, l);
                string lright = "";
                if (l > 0 && l < left.length())
                {
                    lright = left.substr(l, left.length() - l);
                }
                
                if (isValid(lleft, lright))
                {
                    for (int r = 0; r <= right.length(); r++)
                    {
                        string rleft = right.substr(0, r);
                        string rright = "";
                        if (r > 0 && r < right.length())
                        {
                            rright = right.substr(r, right.length() - r);
                        }
                        
                        if (isValid(rleft, rright))
                        {
                            string res = "(";
                            res += lleft;
                            if (lright.length() > 0)
                            {
                                res += ".";
                                res += lright;
                            }
                            
                            res += ", ";
                            res += rleft;
                            
                            if (rright.length() > 0)
                            {
                                res += ".";
                                res += rright;
                            }
                            
                            res += ")";

                            result.push_back(res);
                        }
                    }
                }
            }
        }
        
        return result;
    }
};

// Leetcode 17. Letter Combinations of a Phone Number
// https://leetcode.com/problems/letter-combinations-of-a-phone-number/
// Runtime: 0 ms
// Memory: 6.5 MB (100%)

class Solution 
{
public:
    void combine(const vector<string> &ss, vector<string> &v, int idx, string &s)
    {
        if (idx == ss.size())
        {
            v.push_back(s.data());
            s.pop_back();
            return;
        }
        
        string elem = ss[idx];
        for (int i = 0; i < elem.size(); i++)
        {
            s.push_back(elem[i]);
            combine(ss, v, idx + 1, s);
        }
        
        if (!s.empty())
            s.pop_back();
    }
    
    vector<string> letterCombinations(string digits) 
    {
        vector<string> ret;
        if (digits.empty())
            return ret;
        
        vector<string> tbl;
        tbl.push_back("");
        tbl.push_back("");
        tbl.push_back("abc");
        tbl.push_back("def");
        tbl.push_back("ghi");
        tbl.push_back("jkl");
        tbl.push_back("mno");
        tbl.push_back("pqrs");
        tbl.push_back("tuv");
        tbl.push_back("wxyz");

        vector<string> ss;
        for (int i = 0; i < digits.size(); i++)
        {
            ss.push_back(tbl[digits[i] - '0']);
        }
        string s = "";
        combine(ss, ret, 0, s);
        
        return ret;
    }
};

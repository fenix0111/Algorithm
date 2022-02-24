// Leetcode 756. Pyramid Transition Matrix
// https://leetcode.com/problems/pyramid-transition-matrix/

class Solution
{
public:
    bool check(string& bottom, unordered_map<string, vector<char>>& M, unordered_map<string, int>& tbl)
    {
        if (bottom.length() == 1)
        {
            return true;
        }
        
        if (tbl[bottom] != 0)
        {
            return tbl[bottom] == 1;
        }
        
        bool result = false;
        string buf = "";
        vector<string> res;

        getBottoms(buf, bottom, M, 0, res, tbl);
        
        for (string& s : res)
        {
            if (check(s, M, tbl))
            {
                result = true;
                break;
            }
        }
        
        tbl[bottom] = result == true ? 1 : 2;
        return result;
    }
    
    void getBottoms(string& buf, string& bottom, unordered_map<string, vector<char>>& M, 
                    int index, vector<string>& result, unordered_map<string, int>& tbl)
    {
        if (index == bottom.size() - 1)
        {
            if (tbl[buf] == 2)
            {
                return;
            }
            result.push_back(buf);
            
            return;
        }
        
        string prefix = bottom.substr(index, 2);
        
        vector<char>& tops = M[prefix];
        
        for (char c : tops)
        {
            buf.push_back(c);
            
            getBottoms(buf, bottom, M, index + 1, result, tbl);
            
            buf.pop_back();
        }
    }
    
    bool pyramidTransition(string bottom, vector<string>& allowed)
    {
        unordered_map<string, vector<char>> M;
        unordered_map<string, int> tbl;
        for (string& s : allowed)
        {
            M[s.substr(0, 2)].push_back(s.back());
        }
        
        return check(bottom, M, tbl);
    }
};

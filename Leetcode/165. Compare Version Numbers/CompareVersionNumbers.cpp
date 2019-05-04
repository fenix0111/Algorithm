// Leetcode 165. Compare Version Numbers
// https://leetcode.com/problems/compare-version-numbers/
// Runtime: 4ms

class Solution 
{
public:
    void eraseZeroes(string &s)
    {
        string::iterator it = s.begin();
        while (*it == '0')
        {
            it++;
        }
        s.erase(s.begin(), it);
    }
    
    vector<string> split(const string& s, char delimiter)
    {
       vector<string> tokens;
       string token;
       istringstream tokenStream(s);
       while (std::getline(tokenStream, token, delimiter))
       {
          tokens.push_back(token);
       }
       
       return tokens;
    }
    
    int compareVersion(string version1, string version2)
    {
        vector<string> v1 = split(version1, '.');
        vector<string> v2 = split(version2, '.');
        
        int s1 = v1.size();
        int s2 = v2.size();
        
        int len = s1 < s2 ? s1 : s2;
        
        for (int k = 0; k < len; k++)
        {
            eraseZeroes(v1[k]);
            eraseZeroes(v2[k]);
            
            int i1 = atoi(v1[k].c_str());
            int i2 = atoi(v2[k].c_str());
            
            if (i1 > i2)
            {
                return 1;
            }
            else if (i1 < i2)
            {
                return -1;
            }
        }
        
        if (s1 > s2)
        {
            for (int i = len; i < s1; i++)
            {
                eraseZeroes(v1[i]);
                if (v1[i] != "")
                {
                    return 1;
                }
            }
            return 0;
        }
        else if (s1 < s2)
        {
            for (int i = len; i < s2; i++)
            {
                eraseZeroes(v2[i]);
                if (v2[i] != "")
                {
                    return -1;
                }
            }
            return 0;
        }
        else
        {
            return 0;
        }
    }
};

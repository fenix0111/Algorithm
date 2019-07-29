// Leetcode 819. Most Common Word
// https://leetcode.com/problems/most-common-word/
// Runtime: 4ms

class Solution 
{
public:
    string mostCommonWord(string paragraph, vector<string>& banned) 
    {
        unordered_map<string, bool> bantbl;
        for (string s : banned)
        {
            transform(s.begin(), s.end(), s.begin(), [](unsigned char c){ return tolower(c); });
            bantbl.insert(make_pair(s, true));
        }
        
        unordered_map<string, int> tbl;
        int max = 0;
        string maxstr;
        string s = "";
        for (int i = 0; i < paragraph.size(); i++)
        {
            char c = paragraph[i]; 
            if (isalpha(c))
            {
                s += tolower(c);
            }
            else
            {
                if (!s.empty() && bantbl.find(s) == bantbl.end())
                {
                    auto it = tbl.find(s);
                    if (it == tbl.end())
                    {
                        tbl.insert(make_pair(s, 1));
                        if (1 > max)
                        {
                            max = 1;
                            maxstr = s;
                        }
                    }
                    else
                    {
                        it->second++;
                        if (it->second > max)
                        {
                            max = it->second;
                            maxstr = s;
                        }
                    }
                }
                s = "";
            }
        }
        
        // final check
        if (!s.empty())
        {
            if (bantbl.find(s) == bantbl.end())
            {
                auto it = tbl.find(s);
                if (it == tbl.end())
                {
                    if (1 > max)
                    {
                        max = 1;
                        maxstr = s;
                    }
                }
                else
                {
                    it->second++;
                    if (it->second > max)
                    {
                        max = it->second;
                        maxstr = s;
                    }
                }
            }
        }
        
        return maxstr;
    }
};

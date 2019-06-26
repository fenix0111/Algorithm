// Leetcode 833. Find And Replace in String
// https://leetcode.com/problems/find-and-replace-in-string/
// Runtime: 8ms

class Solution 
{
public:
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) 
    {
        int sz = indexes.size();
        map<int, string> srcmap;
        map<int, string> dstmap;
        for (int i = 0; i < sz; i++)
        {
            srcmap.insert(pair<int, string>(indexes[i], sources[i]));
            dstmap.insert(pair<int, string>(indexes[i], targets[i]));
        }
        
        string ret;
        int last = 0;
        for (auto it = srcmap.begin(); it != srcmap.end(); it++)
        {
            int pos = it->first;
            string src = it->second;
            string comp = S.substr(pos, src.size());
            
            // source not found in S
            if (comp.find(src) == string::npos)
            {
                continue;
            }
            
            string target = dstmap.find(pos)->second;
            int n = last;
            while (n < pos)
            {
                ret += S[n];
                n++;
            }
            last = pos + src.size();
            ret.append(target);
        }
        
        // copy the remaining part
        if (last < S.size())
        {
            for (int j = last; j < S.size(); j++)
            {
                ret += S[j];
            }
        }
        
        return ret;
    }
};

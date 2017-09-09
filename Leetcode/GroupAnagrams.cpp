// Leetcode 49. Group Anagrams
// https://leetcode.com/problems/group-anagrams/description/
// Runtime: 59ms

// submission里最快的是差不多26ms，鄙人的依然有提升空间
// Leetcode 49. Group Anagrams
vector<vector<string>> groupAnagrams(vector<string>& strs)
{
    vector< vector<string> > res;
    map<string, vector<int> > m;
    string tmp;
    for(int i = 0; i < strs.size(); i++)
    {
        tmp = strs[i];
        sort(tmp.begin(), tmp.end());
        if (m.find(tmp) == m.end())
        {
            vector<int> v;
            v.push_back(i);
            m.insert(make_pair(tmp, v));
        }
        else
        {
            m.find(tmp)->second.push_back(i);
        }
    }
    
    for (map< string, vector<int> >::iterator it = m.begin(); it != m.end(); it++)
    {
        vector<int> vtmp = it->second;
        vector<string> stmp;
        for (int j = 0; j < vtmp.size(); j++)
        {
            stmp.push_back(strs[vtmp[j]]);
        }
        res.push_back(stmp);
    }
    
    return res;
}

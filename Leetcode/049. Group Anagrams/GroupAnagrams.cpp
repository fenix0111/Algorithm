// Leetcode 49. Group Anagrams
// https://leetcode.com/problems/group-anagrams/description/
// Runtime: 42ms

// submission里最快的是差不多26ms，鄙人的依然有提升空间
vector<vector<string>> groupAnagrams(vector<string>& strs)
{
    vector< vector<string> > res;
    map<string, vector<int> > m;
    map<string, vector<int> >::iterator it;
    string tmp;
    
    // 对于strs逐个做字符排序存到map里。
    // map里的value为整数vector,保存排序后相同字符串的下标
    for(int i = 0; i < strs.size(); i++)
    {
        tmp = strs[i];
        sort(tmp.begin(), tmp.end());
        it = m.find(tmp);
        if (it == m.end())
        {
            vector<int> v;
            v.push_back(i);
            m.insert(make_pair(tmp, v));
        }
        else
        {
            it->second.push_back(i);
        }
    }
    
    vector<int> vtmp;
    for (map< string, vector<int> >::iterator it = m.begin(); it != m.end(); it++)
    {
        vtmp = it->second;
        vector<string> stmp;
        // 从map取下标把相应下标的strs里的字符串存到结果当中
        for (int j = 0; j < vtmp.size(); j++)
        {
            stmp.push_back(strs[vtmp[j]]);
        }
        res.push_back(stmp);
    }
    
    return res;
}

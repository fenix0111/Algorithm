// Leetcode 140. Word Break II
// https://leetcode.com/problems/word-break-ii/
// time complexity: 
// space complexity:

class Solution 
{
public:
    vector<string> backtrack(vector<string>& ret, string src, int begin, unordered_map<char, unordered_set<string>>& M, unordered_map<string, vector<string>>& visited)
    {
        vector<string> result;
        if (begin >= src.length())
        {
            result.push_back("");
            return result;
        }
        
        string part = src.substr(begin, src.length() - begin);
        
        auto visited_it = visited.find(part);
        if (visited_it != visited.end())
        {
            return visited_it->second;
        }
        
        char begin_char = src[begin];
        auto it = M.find(begin_char);
        
        if (it != M.end())
        {
            unordered_set<string>& words = it->second;
            for (auto sit = words.begin(); sit != words.end(); sit++)
            {
                string word = *sit;
                int find_pos = part.find(word);
                if (find_pos == 0)
                {
                    vector<string> subresult = backtrack(ret, src, begin + word.length(), M, visited);
                    for (int i = 0; i < subresult.size(); i++)
                    {
                        string tmp = "";
                        tmp += word;
                        tmp += subresult[i].empty() ? "" : " " + subresult[i];
                        
                        result.push_back(tmp);
                    }
                }
            }
        }
        
        visited[part] = result;
        return result;
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) 
    {
        unordered_map<char, unordered_set<string>> M;
        unordered_map<string, vector<string>> visited;
        for (string s : wordDict)
        {
            M[s[0]].insert(s);
        }
        
        vector<string> ret = backtrack(ret, s, 0, M, visited);
        return ret;
    }
};

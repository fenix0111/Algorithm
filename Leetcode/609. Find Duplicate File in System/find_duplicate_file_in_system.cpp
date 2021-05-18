// Leetcode 609. Find Duplicate File in System
// https://leetcode.com/problems/find-duplicate-file-in-system/
// 
// 

// the real challenging part is the follow-ups:
// - Imagine you are given a real file system, how will you search files? DFS or BFS?
// - If the file content is very large (GB level), how will you modify your solution?
// - If you can only read the file by 1kb each time, how will you modify your solution?
// - What is the time complexity of your modified solution? What is the most time-consuming part and memory-consuming part of it? How to optimize?
// - How to make sure the duplicated files you find are not false positive?
    
class Solution 
{
public:
    void getDetails(string& str, unordered_map<string, vector<string>>& tbl)
    {
        string dir = "";
        string filename = "";
        string content = "";
        int i = 0;
        while (str[i] != ' ')
        {
            dir.push_back(str[i]);
            i++;
        }
        
        i++;
        
        while (i < str.size())
        {            
            if (str[i] == ' ')
            {
                i++;
                continue;
            }
            
            while (str[i] != '(')
            {
                filename.push_back(str[i]);
                i++;
            }

            i++;
            while (str[i] != ')')
            {
                content.push_back(str[i]);
                i++;
            }
            
            i++;
            
            tbl[content].push_back(dir + "/" + filename);
            content.clear();
            filename.clear();
        }
    }
    
    vector<vector<string>> findDuplicate(vector<string>& paths) 
    {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> tbl;
        for (int i = 0; i < paths.size(); i++)
        {
            string& path = paths[i];
            getDetails(path, tbl);
        }
        
        for (auto it = tbl.begin(); it != tbl.end(); it++)
        {
            if (it->second.size() > 1)
            {
                result.push_back(it->second);
            }
        }
        
        return result;
    }
};

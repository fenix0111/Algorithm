class Solution 
{
public:
    string simplifyPath(string path) 
    {
        vector<string> v;
        string result = "/";
        int i = 0;
        while (i < path.length())
        {
            if (path[i] == '/')
            {
                i++;
            }
            else
            {
                int k = i;
                while (i < path.length() && path[i] != '/')
                {
                    i++;
                }
                
                // check for "..", pop up the stack if true
                if (i - k == 2 && path[k] == '.' && path[k + 1] == '.')
                {
                    if (!v.empty())
                        v.pop_back();
                    
                    continue;
                }
                else if (i - k == 1 && path[k] == '.')
                {
                    // current directory
                    continue;
                }
                else
                {
                    string name = path.substr(k, i - k);
                    v.push_back(name);
                }
            }
        }
        
        for (int j = 0; j < v.size(); j++)
        {
            result += v[j];
            result += "/";
        }
        
        // erase the last slash
        if (result.length() > 1)
            result.pop_back();
        
        return result;
    }
};

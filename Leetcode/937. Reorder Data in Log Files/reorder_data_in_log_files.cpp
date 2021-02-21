// Leetcode 937. Reorder Data in Log Files
// https://leetcode.com/problems/reorder-data-in-log-files/
// time complexity: O(nlogn)
// space complexity: O(n)

class Solution 
{
public:
    vector<string> reorderLogFiles(vector<string>& logs) 
    {
        vector<string> digitLogs;
        vector<string> letterLogs;
        for (string& log : logs)
        {
            if (!isalpha(log.back()))
            {
                digitLogs.push_back(log);
            }
            else
            {
                letterLogs.push_back(log);
            }
        }
        
        // sort letterLogs
        sort(letterLogs.begin(), letterLogs.end(), [](const string& a, const string b) {
            string ida;
            string idb;
            
            int i = 0;
            while (a[i] != ' ')
            {
                i++;
            }
            ida = a.substr(0, i);
            
            int j = 0;
            while (b[j] != ' ')
            {
                j++;
            }
            idb = b.substr(0, j);
            
            while (i < a.length() && j < b.length())
            {
                if (a[i] < b[j]) 
                    return true;
                
                if (a[i] > b[j]) 
                    return false;
                
                i++;
                j++;
            }
            
            if (a.length() - i == b.length() - j)
            {
                return ida.compare(idb) < 0;
            }
            
            return i == a.length();

        });
        
        vector<string> result;
        for (string& log : letterLogs)
        {
            result.push_back(log);
        }
        
        for (string& log : digitLogs)
        {
            result.push_back(log);
        }
        
        return result;
    }
};

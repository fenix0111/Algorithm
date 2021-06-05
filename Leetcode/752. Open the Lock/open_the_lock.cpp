// Leetcode 752. Open the Lock
// https://leetcode.com/problems/open-the-lock/
// 
// 

class Solution 
{
public:
    void add(string& original, string& str, queue<string>& locks, 
             unordered_map<string, int>& distance, unordered_set<string>& deadends)
    {
        if (deadends.count(str) == 0)
        {
            if (distance.count(str) == 0 || (distance[str] > distance[original] + 1))
            {
                distance[str] = distance[original] + 1;
                locks.push(str);
            }
        }
    }
    
    void getLocks(string& s, queue<string>& locks, 
                  unordered_map<string, int>& distance, 
                  unordered_set<string>& deadends)
    {
        string original = s;
        for (int i = 0; i < 4; i++)
        {
            if (s[i] == '0')
            {
                s[i] = '9';
                add(original, s, locks, distance, deadends);
                s[i] = '0';
            }
            else 
            {
                s[i] -= 1;
                add(original, s, locks, distance, deadends);
                s[i] += 1;
            }
            
            if (s[i] == '9')
            {
                s[i] = '0';
                add(original, s, locks, distance, deadends);
                s[i] = '9';
            }
            else 
            {
                s[i] += 1;
                add(original, s, locks, distance, deadends);
                s[i] -= 1;
            }
        }
    }
    
    void bfs(string& num, string& target, unordered_map<string, int>& distance, 
             unordered_set<string>& deadends)
    {
        queue<string> q;
        q.push(num);
        
        while (!q.empty())
        {
            string& str = q.front();
            
            if (deadends.count(str))
            {
                q.pop();
                continue;
            }
            
            if (str.compare(target) == 0)
                return;
            
            getLocks(str, q, distance, deadends);
            
            q.pop();
        }
    }
    
    int openLock(vector<string>& deadends, string target) 
    {
        string num = "0000";
        unordered_set<string> ds;
        for (string& s : deadends)
        {
            ds.insert(s);
        }
        
        unordered_map<string, int> distance;
        distance[num] = 0;
        
        bfs(num, target, distance, ds);
        
        int result = distance.find(target) == distance.end() ? -1 : distance[target];
        
        return result;
    }
};

// Leetcode 433. Minimum Genetic Mutation
// https://leetcode.com/problems/minimum-genetic-mutation/
// time complexity: 
// space complexity:

class Solution
{
public:
    int minMutation(string start, string end, vector<string>& bank)
    {
        if (bank.empty())
        {
            return -1;
        }
        
        unordered_set<string> buf;
        
        for (string& s : bank)
        {
            buf.insert(s);
        }
        
        if (!buf.count(end))
        {
            return -1;
        }
        
        buf.erase(end);
        
        int count = 0;
        queue<string> q;
        q.push(end);
        while (!q.empty())
        {
            int qsize = q.size();
            count++;
            while (qsize > 0)
            {
                string s = q.front();
                q.pop();
                for (int i = 0; i < s.size(); i++)
                {
                    char c = s[i];
                    if (c != 'A')
                    {
                        s[i] = 'A';
                        if (start.compare(s) == 0)
                        {
                            return count;
                        }
                        if (buf.count(s))
                        {
                            q.push(s);
                            buf.erase(s);
                        }
                        s[i] = c;
                    }

                    if (c != 'C')
                    {
                        s[i] = 'C';
                        if (start.compare(s) == 0)
                        {
                            return count;
                        }
                        if (buf.count(s))
                        {
                            q.push(s);
                            buf.erase(s);
                        }
                        s[i] = c;
                    }

                    if (c != 'G')
                    {
                        s[i] = 'G';
                        if (start.compare(s) == 0)
                        {
                            return count;
                        }
                        if (buf.count(s))
                        {
                            q.push(s);
                            buf.erase(s);
                        }
                        s[i] = c;
                    }

                    if (c != 'T')
                    {
                        s[i] = 'T';
                        if (start.compare(s) == 0)
                        {
                            return count;
                        }
                        if (buf.count(s))
                        {
                            q.push(s);
                            buf.erase(s);
                        }
                        s[i] = c;
                    }
                }
                qsize--;
            }
        }
        
        return -1;
    }
};

// Leetcode 636. Exclusive Time of Functions
// https://leetcode.com/problems/exclusive-time-of-functions/submissions/
// time complexity: O(N)
// space complexity: O(N)

typedef struct Func
{
    int id;
    int state; // 1 for start, 2 for end
    int time;
};

class Solution 
{
    Func getFunctionInfo(const string& s)
    {
        Func f;
        int i = 0;
        string buf = "";
        int c = 0;
        while (i < s.length() && s[i] != ':')
        {
            buf.push_back(s[i]);
            i++;
        }
        
        f.id = atoi(buf.c_str());
        buf.clear();
        i++;
        while (i < s.length() && s[i] != ':')
        {
            buf.push_back(s[i]);
            i++;
        }
        
        if (buf.compare("start") == 0)
        {
            f.state = 1;
        }
        else
        {
            f.state = 2;
        }
        
        buf.clear();
        i++;
        while (i < s.length())
        {
            buf.push_back(s[i]);
            i++;
        }
        
        f.time = atoi(buf.c_str());
        
        return f;
    }
    
public:
    vector<int> exclusiveTime(int n, vector<string>& logs)
    {
        stack<Func> frames;
        vector<int> result(n, 0);
        
        // beginning of the last time, not the end of that
        int last_time = 0;
        
        for (string& log : logs)
        {
            Func current = getFunctionInfo(log);
            
            if (frames.empty())
            {
                frames.push(current);
            }
            else
            {
                Func top = frames.top();
                
                // there are only two cases:
                // 1, continuous function starts (no matter recursive or not)
                // 2, end of the function (pop up stack, continue executing previous function)
                if (top.state == 1 && current.state == 1)
                {
                    result[top.id] += (current.time - last_time);
                    frames.push(current);
                }
                else if (top.state == 1 && current.state == 2)
                {
                    result[current.id] += (current.time - last_time + 1);
                    frames.pop();
                }        
            }
            
            if (current.state == 1)
            {
                last_time = current.time;
            }
            else
            {
                last_time = current.time + 1;
            }
        }
        
        return result;
    }
};

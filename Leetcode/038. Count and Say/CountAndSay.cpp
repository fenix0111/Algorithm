// Leetcode 38. Count and Say
// https://leetcode.com/problems/count-and-say/description/
// Runtime: 0ms

// using char instead of string as possible when manipulating string(like append operation)

class Solution 
{
public:
    string countAndSay(int n) 
    {
        string ret;
        vector<string> v = {"0", "1", "11", "21", "1211", "111221"};
        
        int len = v.size();
        
        if (n < len)
            return v[n];
        
        int c = len - 1;
        
        while (c < n)
        {
            string last = v.back();
            string newcount = "";
            
            int numcount = 0;
            int num = -1;
            
            for (int i = 0; i < last.size(); i++)
            {
                char lastc = last[i] - 48;
                if (num == -1)
                {
                    num = lastc;
                    numcount++;
                    continue;
                }
                
                if (num != lastc)
                {
                    newcount.append(1, (char)(numcount + 48));
                    newcount.append(1, (char)(num + 48));
                    numcount = 1;
                    num = lastc;
                }
                else
                {
                    numcount++;
                }
            }
            
            newcount.append(1, (char)(numcount + 48));
            newcount.append(1, (char)(num + 48));
            v.push_back(newcount);
            c++;
        }
        
        return v[n];
    }
};

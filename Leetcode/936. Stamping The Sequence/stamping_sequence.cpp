// Leetcode 936. Stamping The Sequence
// https://leetcode.com/problems/stamping-the-sequence/
// time complexity: O(len(target) * len(stamp))
// space complexity: O(n)

class Solution 
{
public:
    vector<int> movesToStamp(string stamp, string target) {
        int c = 0;
        string s(stamp);
        string t(target);
        vector<bool> visited(target.size(), false);
        vector<int> result;
        while (c < target.length())
        {
            bool can_replace = true;
            for (int i = 0; i <= target.length() - stamp.length(); i++)
            {
                if (!visited[i])
                {
                    if (!canStamp(i, s, t))
                    {
                        can_replace = false;
                        continue;
                    }
                    visited[i] = true;
                    can_replace = true;
                    c += stamping(i, s, t);
                    result.push_back(i);
                }
            }
            
            if (!can_replace)
            {
                return vector<int>();
            }
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
    
    bool canStamp(int idx, string& stamp, string& target)
    {
        for (int i = 0; i < stamp.length(); i++)
        {
            if (target[i + idx] != '*' && target[i + idx] != stamp[i])
            {
                return false;
            }
        }
        
        return true;
    }
    
    int stamping(int idx, string& stamp, string& target)
    {
        int counts = 0;
        for (int i = 0; i < stamp.length(); i++)
        {
            if (target[i + idx] != '*')
            {
                target[i + idx] = '*';
                counts++;
            }
        }
        
        return counts;
    }
};

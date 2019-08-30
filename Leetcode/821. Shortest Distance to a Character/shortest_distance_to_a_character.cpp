// Leetcode 821. Shortest Distance to a Character
// https://leetcode.com/problems/shortest-distance-to-a-character/
// Runtime: 8ms

class Solution 
{
public:
    vector<int> shortestToChar(string S, char C) 
    {
        queue<int> q;
        for (int i = 0; i < S.size(); i++)
        {
            if (S[i] == C)
            {
                q.push(i);
            }
        }
        
        int l = q.front();
        int r = q.front();
        q.pop();
        
        vector<int> ret;
        for (int i = 0; i < S.size(); i++)
        {
            int less_diff;
            if (S[i] == C)
            {
                l = r;
                if (!q.empty())
                {
                    r = q.front();
                    q.pop();
                }
                ret.push_back(0);
            }
            else
            {
                int less_l = abs(i - l);
                int less_r = abs(r - i);
                less_diff = less_l < less_r ? less_l : less_r;
                ret.push_back(less_diff);
            }
        }
        
        return ret;
    }
};

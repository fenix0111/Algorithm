// Leetcode 210. Course Schedule II
// https://leetcode.com/problems/course-schedule-ii/description/


// This solution used Kahn's Algorithm (https://en.wikipedia.org/wiki/Topological_sorting)
// Alternatively, could use DFS to solve the problem.

class Solution 
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
        vector<int> ret;
        queue<int> no_incoming;
        
        unordered_map< int, vector<int> > G;
        vector<int> has_incoming_v(numCourses, 0);
        
        for (int i = 0; i < prerequisites.size(); i++)
        {
            vector<int>& p = prerequisites[i];
            has_incoming_v[p[0]]++;
            
            G[p[1]].push_back(p[0]);
        }
        
        for (int i = 0; i < has_incoming_v.size(); i++)
        {
            if (has_incoming_v[i] == 0)
                no_incoming.push(i);
        }
        
        while (!no_incoming.empty())
        {
            int node = no_incoming.front();
            no_incoming.pop();
            
            ret.push_back(node);
            
            vector<int>& nbr = G[node];
            for (int n : nbr)
            {
                has_incoming_v[n]--;
                if (has_incoming_v[n] == 0)
                {
                    no_incoming.push(n);
                }
            }
        }
        
        for (int i = 0; i < has_incoming_v.size(); i++)
        {
            if (has_incoming_v[i] > 0)
            {
                ret.clear();
                return ret;
            }
        }
        
        return ret;
    }
};

// Leetcode 210. Course Schedule II
// https://leetcode.com/problems/course-schedule-ii/description/
// Runtime: 16ms

// This solution used Kahn's Algorithm (https://en.wikipedia.org/wiki/Topological_sorting)
// Alternatively, could use DFS to solve the problem.

class Solution 
{
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) 
    {
        // p.second ---> p.first
        vector<int> ret;
        list<int> no_incoming;
        
        map< int, set<int> > G;
        vector<int> has_incoming_v(numCourses);
        
        for (int i = 0; i < prerequisites.size(); i++)
        {
            pair<int, int> p = prerequisites[i];
            has_incoming_v[p.first]++;
            if (G.find(p.second) == G.end())
            {
                set<int> tmpset;
                tmpset.insert(p.first);
                G.insert(make_pair(p.second, tmpset));
            }
            else
            {
                G.find(p.second)->second.insert(p.first);
            }
        }
        
        for (int i = 0; i < has_incoming_v.size(); i++)
        {
            if (has_incoming_v[i] == 0)
                no_incoming.push_back(i);
        }
        
        while (!no_incoming.empty())
        {
            int node = no_incoming.front();
            no_incoming.pop_front();
            
            ret.push_back(node);
            
            set<int> nbr = G.find(node)->second;
            for (auto it = nbr.begin(); it != nbr.end(); it++)
            {
                has_incoming_v[*it]--;
                if (has_incoming_v[*it] == 0)
                {
                    no_incoming.push_back(*it);
                }
            }
        }
        
        // check the whether has cycle
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

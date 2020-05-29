// Leetcode 207. Course Schedule
// https://leetcode.com/problems/course-schedule/
// time complexity: O(n)
// space complexity: O(n)

class Solution 
{
public:
    bool has_cycle(const vector< vector<int> > &tbl, int current, vector<bool> &prev, vector<bool>& visited)
    {
        if (tbl[current].empty())
        {
            return false;
        }
        
        if (prev[current])
        {
            return true;
        }
        
        visited[current] = true;
        vector<int> nbr = tbl[current];
        
        for (int i = 0; i < nbr.size(); i++)
        {
            prev[current] = true;
            if (has_cycle(tbl, nbr[i], prev, visited))
            {
                return true;
            }
            prev[current] = false;
        }
        
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        vector< vector<int> > tbl(numCourses);
        for (int i = 0; i < prerequisites.size(); i++)
        {
            vector<int> p = prerequisites[i];
            tbl[p[0]].push_back(p[1]);
        }
        
        vector<bool> prev(numCourses, false);
        vector<bool> visited(numCourses, false);
        
        for (int i = 0; i < tbl.size(); i++)
        {
            if (!visited[i] && has_cycle(tbl, i, prev, visited))
            {
                return false;
            }
        }
        
        return true;
    }
};

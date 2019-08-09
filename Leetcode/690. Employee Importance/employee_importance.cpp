// Leetcode 690. Employee Importance
// https://leetcode.com/problems/employee-importance/
// Runtime: 28ms

/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution 
{
public:
    int getImportance(vector<Employee*> employees, int id) 
    {
        unordered_map<int, Employee*> tbl;
        for (Employee *e : employees)
        {
            tbl.insert(make_pair(e->id, e));
        }
        
        int importance = 0;
        queue<Employee*> q;
        
        Employee *ee = tbl.find(id)->second;
        importance += ee->importance;
        q.push(ee);
        
        while (!q.empty())
        {
            vector<int> sub = q.front()->subordinates;
            q.pop();
            for (int i : sub)
            {
                Employee *ee = tbl.find(i)->second;
                q.push(ee);
                importance += ee->importance;
            }
        }
        
        return importance;
    }
};

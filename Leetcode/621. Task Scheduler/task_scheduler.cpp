// Leetcode 621. Task Scheduler
// https://leetcode.com/problems/task-scheduler/
// time complexity: O(n)
// space complexity: O(size of tasks)

bool comp(pair<char, int>& a, pair<char, int>& b) 
{ 
    return a.second > b.second; 
} 

class Solution 
{
public:
    int leastInterval(vector<char>& tasks, int n) 
    {
        unordered_map<char, int> M;
        for (char task : tasks)
        {
            M[task]++;
        }
        
        vector<pair<char, int>> num_of_tasks;
        for (auto& it : M)
        {
            num_of_tasks.push_back(it);
        }
        
        sort(num_of_tasks.begin(), num_of_tasks.end(), comp);
        
        int schedule = 0;
        int count = tasks.size();
        while (count > 0)
        {
            bool remain = true;
            int cooling = n + 1;
            for (int i = 0; i < num_of_tasks.size(); i++)
            {
                if (num_of_tasks[i].second > 0)
                {
                    num_of_tasks[i].second--;
                    cooling--;
                    count--;
                    schedule++;  
                }
                
                // no idle time
                if (cooling == 0)
                {
                    remain = false;
                    break;
                }
            }
            
            // sorting the tasks again
            sort(num_of_tasks.begin(), num_of_tasks.end(), comp);

            // no remaining tasks, quit the loop
            if (count == 0)
            {
                break;
            }
            
            // enter idle time
            if (remain)
            {
                while (cooling > 0)
                {
                    cooling--;
                    schedule++;
                }
            }
        }
        
        return schedule;
    }
};

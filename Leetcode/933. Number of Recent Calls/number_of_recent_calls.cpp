// Leetcode 933. Number of Recent Calls
// https://leetcode.com/problems/number-of-recent-calls/

class RecentCounter 
{
    queue<int> q;
public:
    RecentCounter() { }
    
    int ping(int t) 
    {
        int begin = t - 3000;
        int end = t;
        q.push(t);
        while (!q.empty())
        {
            int ts = q.front();
            if (ts < begin)
            {
                q.pop();
            }
            else
            {
                break;
            }
        }
        
        return q.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */

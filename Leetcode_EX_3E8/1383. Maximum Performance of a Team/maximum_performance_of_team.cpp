// Leetcode 1383. Maximum Performance of a Team
// https://leetcode.com/problems/maximum-performance-of-a-team/
// time complexity: O(nlogn + nlogk)
// space complexity: O(n)

// long live the priority queue
class Solution 
{
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) 
    {
        int MOD = 1e9 + 7;
        vector<pair<int, int>> engineers;
        for (int i = 0; i < n; i++)
        {
            engineers.push_back(make_pair(speed[i], efficiency[i]));
        }
        
        sort(engineers.begin(), engineers.end(), [](auto x, auto y) {
            return x.second >= y.second;
        });
        
        priority_queue<int, vector<int>, greater<int>> q;
        unsigned long long speedSum = 0;
        unsigned long long result = 0;
        for (auto engineer : engineers)
        {
            int speed = engineer.first;
            int efficiency = engineer.second;
            
            if (q.size() == k)
            {
                speedSum -= q.top();
                q.pop();
            }
            
            q.push(speed);
            speedSum += speed;
            
            result = max(result, speedSum * efficiency);
        }
        
        return result % MOD;
    }
};

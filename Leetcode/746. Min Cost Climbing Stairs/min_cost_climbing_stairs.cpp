// Leetcode 746. Min Cost Climbing Stairs
// https://leetcode.com/problems/min-cost-climbing-stairs/
// time complexity: O(n)
// space complexity: O(1)

class Solution 
{
public:
    int minCostClimbingStairs(vector<int>& cost) 
    {
        int size = cost.size();

        int x = cost[0];
        int y = cost[1];
        for (int i = 2; i < size; i++)
        {
            int mincost = min(cost[i] + y, cost[i] + x);
            x = y;
            y = mincost;
        }
        
        return min(x, y);
    }
};

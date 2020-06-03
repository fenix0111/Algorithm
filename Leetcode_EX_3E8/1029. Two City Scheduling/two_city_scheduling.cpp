// Leetcode 1029. Two City Scheduling
// https://leetcode.com/problems/two-city-scheduling/
// time complexity: O(nlogn)
// space complexity: O(1)

// make min-heap
bool comp(vector<int>& x, vector<int>& y)
{
    return x[0] - x[1] > y[0] - y[1];
}

class Solution 
{
public:
    int twoCitySchedCost(vector<vector<int>>& costs) 
    {
        make_heap(costs.begin(), costs.end(), comp);
        int sz = costs.size();
        sz = sz / 2;
        int count = 0;
        int cost = 0;
        while (count < sz)
        {
            cost += costs[0][0];
            pop_heap(costs.begin(), costs.end(), comp);
            costs.pop_back();
            count++;
        }
        
        for (int i = 0; i < costs.size(); i++)
        {
            cost += costs[i][1];
        }
        
        return cost;
    }
};

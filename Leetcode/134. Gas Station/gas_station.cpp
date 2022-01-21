// Leetcode 134. Gas Station
// https://leetcode.com/problems/gas-station/description/
// Runtime: 4ms

// core idea is very similar to "Minimum Size Subarray Sum"
// using kadane algorithm, find subarray which sum is non negative and length is equal to gas
class Solution
{
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
    {
        int sz = gas.size();
        
        int i = 0;
        int j = 0;
        int sum = 0;
        while ( i < 2 * sz && j - i < sz)
        {
            sum += (gas[j % sz] - cost[j % sz]);
            
            // jump to next to j
            if (sum < 0)
            {
                i = (j + 1);
                j = i;
                sum = 0;
                continue;
            }
            j++;
        }
        
        // found it
        if (sum >= 0 && j - i == sz)
        {
            return i % sz;
        }
        else
        {
            return -1;
        }
    }
};

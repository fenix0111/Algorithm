// Leetcode 134. Gas Station
// https://leetcode.com/problems/gas-station/description/
// Runtime: 4ms

// core idea is very similar to "Minimum Size Subarray Sum"
class Solution 
{
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
    {    
        int len = gas.size();
        if (len == 1)
        {
            if (gas[0] >= cost[0])
            {
                return 0;
            }
            else
            {
                return -1;
            }
        }
        vector<int> v;
        
        for (int i = 0; i < len; i++)
        {
            v.push_back(gas[i] - cost[i]);
        }
        
        int front = 1;
        int follow = 0;
        int remain = v[follow];
        
        while (follow != (front % len))
        {
            if (remain < 0)
            {
                follow++;
                front = follow + 1;
                remain = v[follow];
                continue;
            }
            
            if (remain + v[front % len] < 0)
            {
                follow = front + 1;
                if (follow >= len)
                {
                    break;
                }
                else
                {
                    remain = v[follow];
                }
                front = follow + 1;
            }
            else
            {
                remain = remain + v[front % len];
                front++;
            }
        }
        
        if (follow == (front % len))
        {
            return follow;
        }
        else
        {
            return -1;
        }
    }
};

// Leetcode 1094. Car Pooling
// https://leetcode.com/problems/car-pooling/
// time complexity: O(N*N)
// space complexity: O(1)

// brute force approach
class Solution
{
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) 
    {
        vector<int> passengersAtLocation(1001, 0);
        
        for (vector<int>& trip : trips)
        {
            for (int i = trip[1]; i < trip[2]; i++)
            {
                passengersAtLocation[i] += trip[0];
                if (passengersAtLocation[i] > capacity)
                {
                    return false;
                }
            }        
        }
        
        return true;
    }
};

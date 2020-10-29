// Leetcode 849. Maximize Distance to Closest Person
// https://leetcode.com/problems/maximize-distance-to-closest-person/
// time complexity: O(N)
// space complexity: O(1)

class Solution 
{
public:
    int maxDistToClosest(vector<int>& seats) 
    {
        int maxDistance = -1;
        int last_idx = -1;
        for (int i = 0; i < seats.size(); i++)
        {
            if (seats[i] == 1)
            {
                if (last_idx == -1)
                {
                    if (i > maxDistance)
                    {
                        maxDistance = i;
                    }
                }
                else
                {
                    if ((i - last_idx) / 2 > maxDistance)
                    {
                        maxDistance = (i - last_idx) / 2;
                    }
                }
                
                last_idx = i;
            }
        }   
        
        int backdist = seats.size() - last_idx - 1;        
        
        if (backdist > maxDistance)
        {
            maxDistance = backdist;
        }
        
        return maxDistance;
    }
};

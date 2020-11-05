// Leetcode 1217. Minimum Cost to Move Chips to The Same Position
// https://leetcode.com/problems/minimum-cost-to-move-chips-to-the-same-position/
// time complexity: O(N)
// space complexity: O(1)

class Solution 
{
public:
    int minCostToMoveChips(vector<int>& position) 
    {
        int minCost = 0;
        for (int p : position)
        {
            if (p % 2 == 1)
            {
                minCost++;
            }
        }
        
        int diff = position.size() - minCost;
        
        return diff < minCost ? diff : minCost;
    }
};

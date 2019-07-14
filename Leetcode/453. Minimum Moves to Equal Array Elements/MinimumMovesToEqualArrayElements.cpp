// Leetcode 453. Minimum Moves to Equal Array Elements
// https://leetcode.com/problems/minimum-moves-to-equal-array-elements/
// Runtime: 48ms

// ???
class Solution 
{
public:
    int minMoves(vector<int>& nums) 
    {
        int min = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] < min)
                min = nums[i];
        }
        
        int moves = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            moves += nums[i] - min;
        }
        
        return moves;
    }
};

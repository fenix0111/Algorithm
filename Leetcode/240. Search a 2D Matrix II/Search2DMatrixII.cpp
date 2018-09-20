// Leetcode 240. Search a 2D Matrix II
// https://leetcode.com/problems/search-a-2d-matrix-ii/description/
// Runtime: 84ms

// brutal force solution
class Solution 
{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        bool isFound = false;
        for (auto it = matrix.begin(); it != matrix.end(); it++)
        {
            isFound = binary_search(it->begin(), it->end(), target);
            if (isFound)
                return true;
        }
        
        return isFound;
    }
};


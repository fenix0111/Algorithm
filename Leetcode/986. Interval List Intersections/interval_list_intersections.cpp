// Leetcode 986. Interval List Intersections
// https://leetcode.com/problems/interval-list-intersections/
// time complexity: O(n)
// space complexity: O(1)

class Solution 
{
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) 
    {        
        int ia = 0;
        int ib = 0;
        vector<vector<int>> intersections;
        while (ia < A.size() && ib < B.size())
        {   
            // no intersection between two intervals
            if (A[ia][0] > B[ib][1])
            {
                ib++;
                continue;
            }
            
            if (A[ia][1] < B[ib][0])
            {
                ia++;
                continue;
            }
            
            vector<int> intersection(2, 0);
            
            if (A[ia][0] <= B[ib][0])
            {
                intersection[0] = B[ib][0];
            }
            else
            {
                intersection[0] = A[ia][0];
            }
            
            if (A[ia][1] >= B[ib][1])
            {
                intersection[1] = B[ib][1];
                ib++;
            }
            else
            {
                intersection[1] = A[ia][1];
                ia++;
            }
            
            intersections.push_back(intersection);
        }
        
        return intersections;
    }
};

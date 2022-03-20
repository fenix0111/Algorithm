// Leetcode 1007. Minimum Domino Rotations For Equal Row
// https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/
// time complexity: O(N)
// space complexity: O(1)

// idea:
// 1. count if number(from 1 to 6) appeared in all position, either in one row or both rows 
// 2. count the number of occurences in each row, say T and B, except when number appears both in same position
//    which means there is no need to swap
// 3. keep tracking the minimum(T, B)

class Solution
{
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms)
    {
        int result = INT_MAX;
        int sz = tops.size();
        for (int n = 1; n <= 6; n++)
        {
            int counts = 0;
            int t = 0;
            int b = 0;
            for (int i = 0; i < sz; i++)
            {
                if (tops[i] == n || bottoms[i] == n)
                {
                    counts++;
                    
                    if (tops[i] == n && bottoms[i] != n)
                    {
                        t++;
                    }
                    else if (tops[i] != n && bottoms[i] == n)
                    {
                        b++;
                    }
                }
            }
            
            if (counts < sz)
            {
                continue;
            }
            
            result = min(t, b);
        }
        
        return result == INT_MAX ? -1 : result;
    }
};

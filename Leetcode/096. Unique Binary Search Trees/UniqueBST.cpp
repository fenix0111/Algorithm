// Leetcode 96. Unique Binary Search Trees
// https://leetcode.com/problems/unique-binary-search-trees/
// Runtime: 4ms

class Solution 
{
public:
    int numTrees(int n) 
    {
        int *count = (int*)malloc(sizeof(int) * (n + 1));   
 
        for (int i = 0; i <= n; i++)
        {
            count[i] = 0;
        }
        
        count[0] = 1;
        count[1] = 1;

        for (int i = 2; i <= n; i++) 
        {
            for (int j = 0; j <= i - 1; j++) 
            {
                count[i] += count[j] * count[i - j - 1];
            }
        }

        return count[n];
    }
};

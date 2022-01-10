// Leetcode 547. Number of Provinces
// https://leetcode.com/problems/number-of-provinces/
// time complexity: O(n)
// space complexity: O(n)

class Solution
{
    typedef struct UnionFind
    {
        vector<int> parents;
        UnionFind(int n)
        {
            for (int i = 0; i < n; i++)
            {
                parents.push_back(i);
            }
        }
        
        void Union(int p, int c)
        {
            parents[Find(c)] = Find(p);
        }
        
        int Find(int x)
        {
            if (x == parents[x])
            {
                return x;
            }
            
            return Find(parents[x]);
        }
    };
    
public:
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        int provinces = 0;
        int n = isConnected.size();
        UnionFind uf(n);
        
        // only care about upper triangle matrix
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                if (isConnected[i][j])
                {
                    uf.Union(i, j);
                }
            }
        }
        
        // increment result if parent node point to itself
        for (int i = 0; i < uf.parents.size(); i++)
        {
            if (i == uf.Find(i))
            {
                provinces++;
            }
        }
        
        return provinces;
    }
};

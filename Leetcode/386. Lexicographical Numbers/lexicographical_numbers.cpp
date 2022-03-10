// Leetcode 386. Lexicographical Numbers
// https://leetcode.com/problems/lexicographical-numbers/

class Solution
{
public:
    void dfs(int maxnum, vector<int>& result, int n)
    {
        if (n > maxnum)
        {
            return;
        }
        
        result.push_back(n);
        
        for (int i = 0; i <= 9; i++)
        {
            dfs(maxnum, result, n * 10 + i);
        }
    }
    
    vector<int> lexicalOrder(int n)
    {
        vector<int> result;
        for (int i = 1; i <= 9; i++)
        {
            dfs(n, result, i);
        }
        
        return result;
    }
};

// Leetcode 1345. Jump Game IV
// https://leetcode.com/problems/jump-game-iv/
// time complexity: O(n)
// space complexity: O(n)

// breadth first search
class Solution
{
public:
    int minJumps(vector<int>& arr)
    {
        int sz = arr.size();
        unordered_map<int, vector<int>> M;
        for (int i = 0; i < sz; i++)
        {
            M[arr[i]].push_back(i);
        }
        
        vector<int> tbl(sz, INT_MAX);
        tbl[0] = 0;
        queue<int> q;
        q.push(0);
        while (!q.empty())
        {
            int pos = q.front();
            q.pop();
            
            int forward = pos + 1;
            int back = pos - 1;
            int step = tbl[pos] + 1;
            
            if (forward < sz && step < tbl[forward])
            {
                q.push(forward);
                tbl[forward] = step;
            }
            
            if (back > 0 && step < tbl[back])
            {
                q.push(back);
                tbl[back] = step;
            }
            
            for (int far : M[arr[pos]])
            {
                if (step < tbl[far])
                {
                    q.push(far);
                    tbl[far] = step;
                }
            }
            
            // remove the indices of same value
            M.erase(arr[pos]);
        }
        
        return tbl.back();
    }
};

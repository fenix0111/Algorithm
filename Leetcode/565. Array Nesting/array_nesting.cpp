// Leetcode 565. Array Nesting
// https://leetcode.com/problems/array-nesting/
// time complexity: amortized O(n)
// space complexity: O(n)

class Solution 
{
public:
    int arrayNesting(vector<int>& nums) 
    {
        int result = 0;
        int sz = nums.size();
        vector<bool> visited(sz + 1, false);
        vector<int> count(sz + 1, 0);
        
        int i = 0;
        while (i < nums.size())
        {
            int res = 0;
            int j = i;
            vector<int> q;
            while (visited[j] == false)
            {
                q.push_back(j);
                visited[j] = true;
                j = nums[j];
                res++;
            }
            
            res += count[j];
            
            result = max(res, result);
            i++;
            for (int k = 0; k < q.size(); k++)
            {
                count[q[k]] = res;
            }
        }
        
        return result;
    }
};

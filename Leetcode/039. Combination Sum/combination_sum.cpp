// Leetcode 39. Combination Sum
// https://leetcode.com/problems/combination-sum/

class Solution 
{
public:
    void run(vector<int>& candidates, int index, vector<int>& aux, int target, vector<vector<int>>& result)
    {
        if (index >= candidates.size() || target < 0)
        {
            return;
        }
        
        if (target == 0)
        {
            result.push_back(aux);
            return;
        }
        
        for (int i = index; i < candidates.size(); i++)
        {
            aux.push_back(candidates[i]);
            run(candidates, i, aux, target - candidates[i], result);
            aux.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<vector<int>> result;
        vector<int> tmp;
        run(candidates, 0, tmp, target, result);
        
        return result;
    }
};

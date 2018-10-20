// Leetcode 216.Combination Sum III
// https://leetcode.com/problems/combination-sum-iii/description/
// Runtime: 0ms

// oops, it works.. 0.0
class Solution {
public:
    void helper(set< set<int> > &res, int remain, int target, int cur, set<int> &comb, vector<bool> &tbl)
    {
        if (remain == 0 && target == 0)
        {
            res.insert(comb);
            return;
        }
        
        if (remain == 0 || target < 0)
        {
            return;
        }

        for (int i = cur; i <= 9; i++)
        {
            if (!tbl[i - 1])
            {
                comb.insert(i);
                tbl[i - 1] = true;
                helper(res, remain - 1, target - i, i + 1, comb, tbl);
                
                tbl[i - 1] = false;
                comb.erase(i);
            }
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        set< set<int> > res;
        set<int> combset;
        vector<bool> tbl(9, false);
        helper(res, k, n, 1, combset, tbl);
        
        vector< vector<int> > ret;
        
        for (auto it = res.begin(); it != res.end(); it++)
        {
            set<int> tmpset = *it;
            vector<int> tmpv;
            for(auto sit = tmpset.begin(); sit != tmpset.end(); sit++)
            {
                tmpv.push_back(*sit);
            }
            ret.push_back(tmpv);
        }
        
        return ret;
    }
};

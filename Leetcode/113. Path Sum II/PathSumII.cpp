// Leetcode 113. Path Sum II
// https://leetcode.com/problems/path-sum-ii/description/
// Runtime: 9ms

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 这个问题需要注意负数的情况
// 而且要求是从根节点到叶子节点的和所以必须要判断当前节点是否为叶子节点
// sol改为引用后16ms提速到9ms
class Solution {
public:
    void psRecur(TreeNode *root, int sum, vector<int> &sol, vector< vector<int> > &vec, int target)
    {
        if (root == NULL)
            return;

        int v = root->val;
        sol.push_back(v);

        if (root->left == NULL && root->right == NULL && sum + v != target)
        {
            if (!sol.empty())
                sol.pop_back();
            return;
        }

        if (root->left == NULL && root->right == NULL && sum + v == target)
        {
            vec.push_back(sol);
            sol.pop_back();
            return;
        }

        psRecur(root->left, sum + v, sol, vec, target);
        psRecur(root->right, sum + v, sol, vec, target);
        
        // 不要忘记弹出尾端元素
        if (!sol.empty())
            sol.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) 
    {
        vector< vector<int> > res;
        vector<int> solution;
        psRecur(root, 0, solution, res, sum);
        return res;
    }
};

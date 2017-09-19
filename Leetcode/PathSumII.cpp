// Leetcode 113. Path Sum II
// https://leetcode.com/problems/path-sum-ii/description/
// Runtime: 16ms

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
void psRecur(TreeNode *root, int sum, vector<int> sol, vector< vector<int> > &vec, int target)
{
	if (root == NULL)
	{
		if (!sol.empty())
			sol.pop_back();
		return;
	}

	int v = root->val;
	sol.push_back(v);
	if (root->left == NULL && root->right == NULL && sum + v == target)
	{
		vec.push_back(sol);
		sol.pop_back();
		return;
	}

	psRecur(root->left, sum + v, sol, vec, target);
	psRecur(root->right, sum + v, sol, vec, target);
}

vector<vector<int>> pathSum(TreeNode* root, int sum) 
{
	vector< vector<int> > res;
	vector<int> solution;
	psRecur(root, 0, solution, res, sum);
	return res;
}
};

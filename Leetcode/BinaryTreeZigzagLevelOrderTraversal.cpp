// Leetcode 103. Binary Tree Zigzag Level Order Traversal
// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/
// Runtime: 6 ms

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 // 跟102题类似,仅仅加了反向判断
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector< vector<int> > res;
	if (root == NULL)
	{
		return res;
	}

	queue<TreeNode*> q;
	q.push(root);
	bool ltor = true;
	while (!q.empty())
	{
		queue<TreeNode*> tmp_q;
		vector<int> v;

		while (!q.empty())
		{
			TreeNode *t = (TreeNode*)malloc(sizeof(TreeNode));
			t = q.front();

			if (t->left)
			{
				tmp_q.push(t->left);
			}
			if (t->right)
			{
				tmp_q.push(t->right);
			}

			v.push_back(t->val);
			q.pop();
		}

		while (!tmp_q.empty())
		{
			q.push(tmp_q.front());
			tmp_q.pop();
		}

		if (ltor)
		{
			res.push_back(v);
		}
		else
		{
			// right to left
			vector<int> r;
			for (vector<int>::reverse_iterator rit = v.rbegin(); rit != v.rend(); rit++)
			{
				r.push_back(*rit);
			}
			res.push_back(r);
		}

		ltor = !ltor;
	}

	return res;
    }
};

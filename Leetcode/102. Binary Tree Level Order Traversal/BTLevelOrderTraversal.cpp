// Leetcode 102. Binary Tree Level Order Traversal
// https://leetcode.com/problems/binary-tree-level-order-traversal/description/
// Runtime: 6ms

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 又一个广度优先搜索题
class Solution {
public:
    vector< vector<int> > levelOrder(TreeNode* root) 
    {
        vector< vector<int> > res;
        if (root == NULL)
            return res;

        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
            queue<TreeNode*> tmp_q;
            vector<int> v;
            
            while (!q.empty())
            {
                TreeNode *t = (TreeNode*)malloc(sizeof(TreeNode));
                t = q.front();
			
                if (t->left)
                    tmp_q.push(t->left);
            
                if (t->right)
                    tmp_q.push(t->right);

                v.push_back(t->val);
                q.pop();
            }
           
            while (!tmp_q.empty())
            {
                q.push(tmp_q.front());
                tmp_q.pop();
            }
            res.push_back(v);
        }
        
        return res;
    }
};

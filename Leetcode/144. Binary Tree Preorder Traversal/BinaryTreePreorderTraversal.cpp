// Leetcode 144. Binary Tree Preorder Traversal
// https://leetcode.com/problems/binary-tree-preorder-traversal/description/
// Runtime: 0ms

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution 
{
public:
    vector<int> preorderTraversal(TreeNode* root) 
    {
        vector<int> ret;
        
        list<TreeNode*> q; // a bit mismatched variable name
        q.push_back(root);
        
        while (!q.empty())
        {
            TreeNode *tmp = q.front();
            if (tmp == NULL)
            {
                q.pop_front();
                continue;
            }
            else
            {
                ret.push_back(tmp->val);
                q.pop_front();
                if (tmp->right)
                {
                    q.push_front(tmp->right);
                }
                
                if (tmp->left)
                {
                    q.push_front(tmp->left);
                }
            }
        }
        
        return ret;
    }
};

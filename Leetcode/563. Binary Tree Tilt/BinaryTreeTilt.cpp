// Leetcode 563. Binary Tree Tilt
// https://leetcode.com/problems/binary-tree-tilt/
// Runtime: 28ms

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 // naive solution
 // while BFS, for each node using post-order travarsal to calculate the tilt
class Solution 
{
public:
    int sum(TreeNode *node)
    {
        if (node)
        {
            return sum(node->left) + sum(node->right) + node->val;
        }
        else
        {
            return 0;
        }
    }
    
    int findTilt(TreeNode* root) 
    {
        if (root)
        {
            TreeNode *node = NULL;
            int tilt = 0;
            int lval = 0;
            int rval = 0;
            queue<TreeNode*> q;
            q.push(root);
            
            while (!q.empty())
            {
                node = q.front();
                q.pop();
                lval = sum(node->left);
                rval = sum(node->right);
                
                if (node->left)
                    q.push(node->left);
                
                if (node->right)
                    q.push(node->right);
                
                tilt += abs(lval - rval);
            }
            
            return tilt;
        }
        
        return 0;
    }
};

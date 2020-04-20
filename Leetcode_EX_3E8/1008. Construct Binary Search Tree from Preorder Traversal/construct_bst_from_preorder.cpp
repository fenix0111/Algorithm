// Leetcode 1008. Construct Binary Search Tree from Preorder Traversal
// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
// Runtime: 0 ms
// Memory: 10.5 M

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 // no special trick, just go over the preorder vector, and find proper node to insert into
class Solution 
{
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) 
    {
        TreeNode *root = new TreeNode(preorder[0]);
        
        for (int i = 1; i < preorder.size(); i++)
        {
            TreeNode *node = root;
            int rv = root->val;
            while (node->left || node->right)
            {
                if (preorder[i] < node->val)
                {
                    rv = node->val;
                    if (!node->left)
                        break;
                    
                    node = node->left;
                }
                else
                {
                    rv = node->val;
                    if (!node->right)
                        break;
                    
                    node = node->right;
                }
            }
            
            if (preorder[i] < node->val)
            {
                node->left = new TreeNode(preorder[i]);
            }
            else
            {
                node->right = new TreeNode(preorder[i]);
            }
        }
        
        return root;
    }
};

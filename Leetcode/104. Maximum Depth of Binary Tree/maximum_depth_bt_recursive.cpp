/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution 
{
public:
    int maxDepth(TreeNode* root) 
    {
        if (!root)
            return 0;
        
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        
        int localMax = max(leftDepth, rightDepth);
        
        return localMax + 1;
    }
};

// the code above could be abbreviated as
// return root == NULL ? 0 : max(maxDepth(root->left), maxDepth(root->right)) + 1;  

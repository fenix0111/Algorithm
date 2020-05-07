// Leetcode 993. Cousins in Binary Tree
// https://leetcode.com/problems/cousins-in-binary-tree/
// Runtime: 4 ms
// Memory: 11 MB

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
    int find(TreeNode* node, int target, int depth, int x, int y)
    {
        if (node)
        {
            if (node->val == target)
            {
                return depth;
            }
            else
            {
                if (node->left && node->right)
                {
                    // check if two target node are children of the same parent
                    if ((node->left->val == x && node->right->val == y) ||
                        (node->left->val == y && node->right->val == x))
                    {
                        return -1;
                    }
                }
                
                int ll = find(node->left, target, depth + 1, x, y);
                int rr = find(node->right, target, depth + 1, x, y);
                if (ll != -1)
                {
                    return ll;
                }
                
                if (rr != -1)
                {
                    return rr;
                }
                
                return -1;
            }
        }
        else
        {
            return -1;
        }
    }
    
    bool isCousins(TreeNode* root, int x, int y) 
    {        
        int ldepth = find(root, x, 1, x, y);
        int rdepth = find(root, y, 1, x, y);
        
        if (ldepth == rdepth && ldepth != -1 && rdepth != -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

// Leetcode 623. Add One Row to Tree
// https://leetcode.com/problems/add-one-row-to-tree/
// time complexity: O(n)
// space complexity: O(n)

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
    void addRow(int currentDepth, TreeNode* p, int v, int d)
    {
        if (!p) return;
        
        if (currentDepth == d)
        {
            TreeNode* newLeftNode = new TreeNode(v);
            TreeNode* newRightNode = new TreeNode(v);
            
            newLeftNode->left = p->left;
            newRightNode->right = p->right;
            
            p->left = newLeftNode;
            p->right = newRightNode;
        }
        else
        {
            addRow(currentDepth + 1, p->left, v, d);
            addRow(currentDepth + 1, p->right, v, d);
        }
    }
    
    TreeNode* addOneRow(TreeNode* root, int v, int d) 
    {
        if (d == 1)
        {
            TreeNode* newRoot = new TreeNode(v);
            newRoot->left = root;
            return newRoot;
        }
        
        addRow(2, root, v, d);
        
        return root;
    }
};

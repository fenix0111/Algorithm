// Leetcode 971. Flip Binary Tree To Match Preorder Traversal
// https://leetcode.com/problems/flip-binary-tree-to-match-preorder-traversal/
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
    void flip(TreeNode* node, int& i, vector<int>& result, vector<int>& voyage)
    {
        if (node)
        {
            if (node->val != voyage[i])
            {
                return;
            }
            
            i += 1;
            
            // flip the tree
            if (node->left && node->left->val != voyage[i])
            {
                result.push_back(node->val);
                
                TreeNode* tmp = node->left;
                node->left = node->right;
                node->right = tmp;
            }
            
            flip(node->left, i, result, voyage);
            flip(node->right, i, result, voyage);
        }
    }
    
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) 
    {
        vector<int> result;
        int i = 0;
        flip(root, i, result, voyage);
        
        if (i < voyage.size())
        {
            result.clear();
            result.push_back(-1);
        }
        
        return result;
    }
};

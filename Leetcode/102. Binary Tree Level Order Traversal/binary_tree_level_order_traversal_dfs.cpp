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
    void traverse(TreeNode* node, vector<vector<int>>& result, int depth)
    {
        if (node)
        {
            if (depth > result.size())
            {
                result.push_back({});
            }
            
            result[depth - 1].push_back(node->val);
            
            traverse(node->left, result, depth + 1);
            traverse(node->right, result, depth + 1);
        }
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int>> result;
        traverse(root, result, 1);
        
        return result;
    }
};

// Leetcode 1110. Delete Nodes And Return Forest
// https://leetcode.com/problems/delete-nodes-and-return-forest/
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
    TreeNode* deleteNode(TreeNode* node, vector<TreeNode*>& result, unordered_set<int>& target)
    {
        if (node)
        {
            if (target.count(node->val))
            {
                TreeNode* l = deleteNode(node->left, result, target);
                TreeNode* r = deleteNode(node->right, result, target);
                if (l)
                {
                    result.push_back(l);
                }
                
                if (r)
                {
                    result.push_back(r);
                }
                
                return nullptr;
            }
            
            node->left = deleteNode(node->left, result, target);
            node->right = deleteNode(node->right, result, target);
        }
        
        return node;
    }
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) 
    {
        vector<TreeNode*> result;
        unordered_set<int> target(to_delete.begin(), to_delete.end());
        
        TreeNode* r = deleteNode(root, result, target);
        
        if (r)
        {
            result.push_back(r);
        }
        
        return result;
    }
};

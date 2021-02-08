// Leetcode 513. Find Bottom Left Tree Value
// https://leetcode.com/problems/find-bottom-left-tree-value/
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
 
 // breadth-first search
class Solution 
{
public:
    int findBottomLeftValue(TreeNode* root) 
    {
        int left_value = 0;
        queue<TreeNode*> q;
        q.push(root);
        int sz = 0;
        TreeNode* node = nullptr;
        while (!q.empty())
        {
            sz = q.size();
            left_value = q.front()->val;
            while (sz > 0)
            {
                node = q.front();
                if (node->left)
                {
                    q.push(node->left);
                }
                
                if (node->right)
                {
                    q.push(node->right);
                }
                q.pop();
                sz--;
            }
        }
        
        return left_value;
    }
};

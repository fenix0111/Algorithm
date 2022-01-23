// Leetcode 1161. Maximum Level Sum of a Binary Tree
// https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/
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
    int maxLevelSum(TreeNode* root)
    {
        queue<TreeNode*> q;
        q.push(root);
        int max_sum = INT_MIN;
        int min_level = 0;
        int level = 1;
        while (!q.empty())
        {
            int sz = q.size();
            int sum = 0;
            while (sz > 0)
            {
                TreeNode* node = q.front();
                q.pop();
                
                sum += node->val;
                if (node->left)
                {
                    q.push(node->left);
                }
                
                if (node->right)
                {
                    q.push(node->right);
                }
                sz--;
            }
            
            if (sum > max_sum)
            {
                max_sum = sum;
                min_level = level;
            }
            
            level++;
        }
        
        return min_level;
    }
};

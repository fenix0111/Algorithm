// Leetcode 515. Find Largest Value in Each Tree Row
// https://leetcode.com/problems/find-largest-value-in-each-tree-row/
// Runtime: 20ms

// Related:
// 1026. Maximum Difference Between Node and Ancestor
// 1162. As Far from Land as Possible

// 
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
// using double queue
class Solution 
{
public:
    vector<int> largestValues(TreeNode* root) 
    {
        queue<TreeNode*> q;
        queue<TreeNode*> tmp;
        vector<int> ret;
        if (root)
        {
            q.push(root);
            while (!q.empty())
            {
                int max = INT_MIN;
                while (!q.empty())
                {
                    TreeNode *node = q.front();
                    if (node->val > max)
                        max = node->val;

                    if (node->left)
                        tmp.push(node->left);
                    
                    if (node->right)
                        tmp.push(node->right);
                    
                    q.pop();
                }
                
                while (!tmp.empty())
                {
                    q.push(tmp.front());
                    tmp.pop();
                }

                ret.push_back(max);
            }
        }
        
        return ret;
    }
};

// Leetcode 1022. Sum of Root To Leaf Binary Numbers
// https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/
// time complexity: O(#nodes)
// space complexity: 

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
    void run(TreeNode* node, int& ret, int sum)
    {
        if (node)
        {           
            // current node is leaf node
            if (node->left == NULL && node->right == NULL)
            {
                ret += (sum << 1) + node->val;
                return;
            }
            run(node->left, ret, (sum << 1) + node->val);
            run(node->right, ret, (sum << 1) + node->val);
        }
    }
    
    int sumRootToLeaf(TreeNode* root) 
    {
        int sum = 0;
        run(root, sum, 0);
        
        return sum;
    }
};

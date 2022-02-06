// Leetcode 1315. Sum of Nodes with Even-Valued Grandparent
// https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/
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

// nothing special, very straighforward
class Solution
{
public:
    bool isEven(int num)
    {
        return (num & 1) == 0;
    }
    
    int sumEvenGrandparent(TreeNode* root)
    {
        int sum = 0;
        if (root)
        {
            if (isEven(root->val))
            {
                if (root->left && root->left->left)
                {
                    sum += root->left->left->val;
                }
                
                if (root->left && root->left->right)
                {
                    sum += root->left->right->val;
                }
                
                if (root->right && root->right->left)
                {
                    sum += root->right->left->val;
                }
                
                if (root->right && root->right->right)
                {
                    sum += root->right->right->val;
                }
            }
            
            sum += sumEvenGrandparent(root->left);
            sum += sumEvenGrandparent(root->right);
        }
        
        return sum;
    }
};

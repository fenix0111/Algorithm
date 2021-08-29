// Leetcode 1339. Maximum Product of Splitted Binary Tree
// https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/
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
    TreeNode* replicateTree(TreeNode* originalNode)
    {
        if (originalNode)
        {
            TreeNode* newNode = new TreeNode(originalNode->val);
            newNode->left = replicateTree(originalNode->left);
            newNode->right = replicateTree(originalNode->right);
            return newNode;
        }
        
        return nullptr;
    }
    
    int calculateSum(TreeNode* node)
    {
        if (node)
        {
            node->val += calculateSum(node->left);
            node->val += calculateSum(node->right);
            return node->val;
        }
        
        return 0;
    }
    
    void findMaxProduct(TreeNode* node, unsigned long long& result, int sum)
    {
        if (node)
        {
            unsigned long long maxval = 0;
            if (node->left)
            {
                int cut_left = (sum - node->left->val);
                maxval = (unsigned long long)cut_left * node->left->val;
            }
            
            if (node->right)
            {
                int cut_right = (sum - node->right->val);
                maxval = max(maxval, (unsigned long long)cut_right * node->right->val);
            }
            
            result = max(maxval, result);
            
            findMaxProduct(node->left, result, sum);
            findMaxProduct(node->right, result, sum);
        }
    }
    
    int maxProduct(TreeNode* root) 
    {
        //TreeNode* newRoot = replicateTree(root);
        unsigned long long result = 0;
        int sum = calculateSum(root);
        findMaxProduct(root, result, sum);
        
        return (int)(result % (1000000000 + 7));
    }
};

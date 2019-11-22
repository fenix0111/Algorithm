// Leetcode 654. Maximum Binary Tree
// https://leetcode.com/problems/maximum-binary-tree/
// Runtime: 68ms

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
class Solution 
{
public:
    // using pointer-to-pointer to change the value which pointed by node
    void helper(TreeNode **node, int l, int r, vector<int> &nums)
    {
        if (l < r) 
        {
            int pos = 0;
            int max = INT_MIN;
            
            // hot spot? 
            for (int i = l; i < r; i++)
            {
                if (nums[i] > max)
                {
                    max = nums[i];
                    pos = i;
                }
            }
            *node = new TreeNode(max);            
            helper(&(*node)->left, l, pos, nums); // a bit tricky part
            helper(&(*node)->right, pos + 1, r, nums);
        }
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) 
    {
        if (nums.size() == 0)
        {
            return NULL;
        }
        
        int l = 0;
        int r = 0;
        int pos = 0;
        int max = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > max)
            {
                max = nums[i];
                pos = i;
            }
        }
        TreeNode *root = new TreeNode(max);
        helper(&(root->left), 0, pos, nums);
        helper(&(root->right), pos + 1, nums.size(), nums);
        
        return root;
    }
};

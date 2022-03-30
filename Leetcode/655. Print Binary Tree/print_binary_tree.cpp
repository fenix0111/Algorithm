// Leetcode 655. Print Binary Tree
// https://leetcode.com/problems/print-binary-tree/
// time complexity: O(N)
// space complexity: O(N)

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

// just do as problem statement says
class Solution
{
public:
    int getHeight(const TreeNode* node)
    {
        if (node == nullptr)
        {
            return 0;
        }
        
        return max(getHeight(node->left), getHeight(node->right)) + 1;
    }
    
    void printTree(TreeNode* node, vector<vector<string>>& result, int row, int col, int height)
    {        
        result[row][col] = to_string(node->val);
        
        if (node->left)
            printTree(node->left, result, row + 1, col - (1 << (height - row - 1)), height);
        
        if (node->right)
            printTree(node->right, result, row + 1, col + (1 << (height - row - 1)), height);
    }
    
    vector<vector<string>> printTree(TreeNode* root) 
    {
        int height = getHeight(root) - 1; // root node is not counted
        int cols = (1 << (height + 1)) - 1;
        vector<vector<string>> result(height + 1, vector<string>(cols, "")); 
        
        printTree(root, result, 0, (cols - 1) / 2, height);
        
        return result;
    }
};

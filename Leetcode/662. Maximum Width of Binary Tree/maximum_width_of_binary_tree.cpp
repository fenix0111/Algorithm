// Leetcode 662. Maximum Width of Binary Tree
// https://leetcode.com/problems/maximum-width-of-binary-tree/
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
class Solution {
public:
    void run(TreeNode* node, unsigned long long val, unordered_map<int, vector<unsigned long long>>& distance, int height)
    {
        if (node)
        {
            distance[height].push_back(val);
            run(node->left, val * 2, distance, height + 1);
            run(node->right, val * 2 + 1, distance, height + 1);
        }
    }
    
    int widthOfBinaryTree(TreeNode* root) 
    {
        unordered_map<int, vector<unsigned long long>> distance;
        run(root, 1, distance, 1);
        
        int max_width = INT_MIN;
        for (auto it = distance.begin(); it != distance.end(); it++)
        {
            vector<unsigned long long>& v = it->second;
            int diff = v[v.size() - 1] - v[0];
            if (diff > max_width)
            {
                max_width = diff;
            }
        }
        
        return max_width + 1;
    }
};

// Leetcode 652. Find Duplicate Subtrees
// https://leetcode.com/problems/find-duplicate-subtrees/
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

// using DFS collect info of each subtree then save to hashmap
// finally get any TreeNode from hashmap which size is greater than 1
// size greater than 1 means that several nodes has subtree with same structured

class Solution
{
public:
    string getInfo(TreeNode* node, unordered_map<string, vector<TreeNode*>>& M)
    {
        if (node)
        {
            string left = getInfo(node->left, M);
            string right = getInfo(node->right, M);
            
            string key = to_string(node->val) + "L" + left + "R" + right;
            M[key].push_back(node);
            
            return key;
        }
        
        return "";
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) 
    {
        // <info of subtree -> TreeNode>
        // info of substree current node val + L + left child + R + right child
        unordered_map<string, vector<TreeNode*>> M;
        vector<TreeNode*> result;
        
        getInfo(root, M);
        for (auto it = M.begin(); it != M.end(); it++)
        {
            if (it->second.size() > 1)
            {
                result.push_back(it->second[0]);
            }
        }
        
        return result;
    }
};

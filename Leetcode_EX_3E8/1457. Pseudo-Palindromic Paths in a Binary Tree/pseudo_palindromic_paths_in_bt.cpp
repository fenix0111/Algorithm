// Leetcode 1457. Pseudo-Palindromic Paths in a Binary Tree
// https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/
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
    void check(TreeNode* node, unordered_map<int, int>& tbl, int& result)
    {
        if (node)
        {
            tbl[node->val]++;
            if (node->left == nullptr && node->right == nullptr)
            {
                bool has_odd = false;
                bool valid = true;
                for (auto it = tbl.begin(); it != tbl.end(); it++)
                {
                    if (it->second % 2 == 1)
                    {
                        if (has_odd)
                        {
                            valid = false;
                            break;
                        }
                        else
                        {
                            has_odd = true;
                        }
                    }
                }
                
                if (valid)
                {
                    result += 1;
                }
            }
            else
            {
                check(node->left, tbl, result);
                check(node->right, tbl, result);
            }
            
            tbl[node->val]--;
        }
    }
    
    int pseudoPalindromicPaths (TreeNode* root) 
    {
        unordered_map<int, int> tbl;
        int result = 0;
        
        check(root, tbl, result);
        
        return result;
    }
};

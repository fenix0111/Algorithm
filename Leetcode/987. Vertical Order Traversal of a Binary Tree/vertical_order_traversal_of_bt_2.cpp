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
 
 // map in the map
class Solution 
{
public:
    void tagging(TreeNode* root, int x, int y, map<int, map<int, vector<int>>>& M)
    {
        if (root)
        {
            M[x][y].push_back(root->val);
            tagging(root->left, x - 1, y + 1, M);
            tagging(root->right, x + 1, y + 1, M);
        }
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) 
    {
        map<int, map<int, vector<int>>> M;
        vector<vector<int>> result;
        
        tagging(root, 0, 0, M);
        
        for (auto it = M.begin(); it != M.end(); it++)
        {
            vector<int> v;
            for (auto it2 = it->second.begin(); it2 != it->second.end(); it2++)
            {
                vector<int>& elems = it2->second;
                sort(elems.begin(), elems.end());
                v.insert(v.end(), elems.begin(), elems.end());
            }
            result.push_back(v);
        }
        
        return result;
    }
};

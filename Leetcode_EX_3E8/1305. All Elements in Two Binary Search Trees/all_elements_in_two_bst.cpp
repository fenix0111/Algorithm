// Leetcode 1305. All Elements in Two Binary Search Trees
// https://leetcode.com/problems/all-elements-in-two-binary-search-trees/
// time complexity: O(#nodes of trees)
// space complexity: O(#nodes of trees)

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
 
// trivial solution
class Solution 
{
public:
    void collect(TreeNode* node, vector<int>& data)
    {
        if (node)
        {
            collect(node->left, data);
            data.push_back(node->val);
            collect(node->right, data);
        }
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) 
    {
        // it is also possible to using one array to collect the data then sort it 
        // here using two extra arrays to avoid sorting(it cost O(nlogn))
        vector<int> data1;
        vector<int> data2;
        vector<int> data;
        collect(root1, data1);
        collect(root2, data2);
        
        int i1 = 0;
        int i2 = 0;
        
        // merging
        while (i1 < data1.size() && i2 < data2.size())
        {
            if (data1[i1] < data2[i2])
            {
                data.push_back(data1[i1]);
                i1++;
            }
            else
            {
                data.push_back(data2[i2]);
                i2++;
            }
        }
        
        while (i1 < data1.size())
        {
            data.push_back(data1[i1]);
            i1++;
        }
        
        while (i2 < data2.size())
        {
            data.push_back(data2[i2]);
            i2++;
        }
        
        return data;
    }
};

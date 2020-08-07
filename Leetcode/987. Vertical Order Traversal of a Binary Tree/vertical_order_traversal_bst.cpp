// Leetcode 987. Vertical Order Traversal of a Binary Tree
// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
// time complexity: O(N * logN)
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
struct comp
{
    bool operator()(pair<int,int>& A, pair<int,int>& B)
    {
        if (A.second < B.second)
        {
            return true;
        }
        else if (A.second == B.second)
        {
            // tie breaking
            return A.first > B.first;
        }
        else
        {
            return false;
        }
    }
};

class Solution 
{
public:
    void run(TreeNode* node, map< int, priority_queue< pair<int,int>, vector<pair<int,int>>, comp> >& M, int x, int y)
    {
        if (node)
        {
            M[x].push(make_pair(node->val, y));
            run(node->left, M, x - 1, y - 1);
            run(node->right, M, x + 1, y - 1);
        }
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) 
    {
        map< int, priority_queue<pair<int,int>, vector<pair<int,int>>, comp> > M;
        run(root, M, 0, 0);
        
        vector<vector<int>> ret;
        for (auto it = M.begin(); it != M.end(); it++)
        {
            vector<int> v;
            auto q = it->second;
            while (!q.empty())
            {
                v.push_back(q.top().first);
                q.pop();
            }
            
            ret.push_back(v);
        }
        
        return ret;
    }
};

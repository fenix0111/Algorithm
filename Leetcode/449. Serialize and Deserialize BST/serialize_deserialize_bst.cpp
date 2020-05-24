// Leetcode 449. Serialize and Deserialize BST
// https://leetcode.com/problems/serialize-and-deserialize-bst/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
// using pre-order traversal
// it is easy to use vector to deserialize
class Codec 
{
    int idx = 0;
public:
    void preorder(TreeNode* node, string& s)
    {
        if (node)
        {
            s += to_string(node->val);
            s += ",";
            preorder(node->left, s);
            preorder(node->right, s);
        }
    }
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) 
    {
        string ret = "";
        preorder(root, ret);
        
        if (ret.length() > 0)
            ret.pop_back();
        
        return ret;
    }

    TreeNode* make_tree(vector<int> &v, int maxval = INT_MAX)
    {
        if (idx >= v.size() || v[idx] > maxval)
            return NULL;
        
        TreeNode* node = new TreeNode(v[idx++]);
        node->left = make_tree(v, node->val);
        node->right = make_tree(v, maxval);
        
        return node;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) 
    {
        string const delims{ "," };

        size_t beg, pos = 0;
        vector<int> v;
        while ((beg = data.find_first_not_of(delims, pos)) != string::npos)
        {
            pos = data.find_first_of(delims, beg + 1);
            
            v.push_back(stoi(data.substr(beg, pos - beg)));
        }

        int idx = 0;
        return make_tree(v);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

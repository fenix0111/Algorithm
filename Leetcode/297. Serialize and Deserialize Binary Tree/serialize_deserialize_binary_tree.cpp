// Leetcode 297. Serialize and Deserialize Binary Tree
// https://leetcode.com/problems/serialize-and-deserialize-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec 
{
public:
    void serialize(TreeNode* node, string& result)
    {
        if (node)
        {
            result += to_string(node->val);
            result.push_back(',');
            serialize(node->left, result);
            serialize(node->right, result);
        }
        else
        {
            result.push_back('$');
            result.push_back(',');
        }
    }
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) 
    {
        string result = "";
        serialize(root, result);
        result.pop_back();  // pop out last comma
        
        return result;
    }

    TreeNode* deserialize(string& data, int& idx)
    {
        if (idx >= data.size())
        {
            return NULL;
        }
        
        if (data[idx] == ',')
        {
            // skip to next index
            idx = idx + 1;
            return deserialize(data, idx);
        }
        else
        {
            if (data[idx] != '$')
            {
                int newval = 0;
                bool neg = false;
                
                // check negative
                if (data[idx] == '-')
                {
                    neg = true;
                    idx++;
                }
                
                while (idx < data.size() && isdigit(data[idx]))
                {
                    newval *= 10;
                    newval += (data[idx] - '0');
                    idx++;
                }
                
                idx--;
                
                if (neg)
                {
                    newval = -newval;
                }
                
                TreeNode* node = new TreeNode(newval);
                idx = idx + 1;
                node->left = deserialize(data, idx);
                idx = idx + 1;
                node->right = deserialize(data, idx);
                
                return node;
            }
        }
        
        return NULL;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) 
    {
        int index = 0;
        return deserialize(data, index);
    }
};

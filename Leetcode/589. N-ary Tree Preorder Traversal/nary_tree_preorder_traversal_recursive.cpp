/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution 
{
public:
    void preorder(Node* node, vector<int>& result)
    {
        if (node)
        {
            result.push_back(node->val);
            for (Node* child : node->children)
            {
                preorder(child, result);
            }
        }
    }
    
    vector<int> preorder(Node* root) 
    {
        vector<int> result;
        preorder(root, result);
        
        return result;
    }
};

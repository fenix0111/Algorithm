// Leetcode 559. Maximum Depth of N-ary Tree
// https://leetcode.com/problems/maximum-depth-of-n-ary-tree/
// Runtime: 144ms (not fast)

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution 
{
public:
    void traverse(Node *node, int local_max, int &max)
    {
        if (node)
        {
            if (local_max > max)
            {
                max = local_max;
            }
            
            for (Node *cnode : node->children)
            {
                traverse(cnode, local_max + 1, max);
            }
        }
    }
    
    int maxDepth(Node* root) 
    {
        if (root == NULL)
            return 0;
        
        int max = 1;
        traverse(root, 1, max);
        return max;
    }
};

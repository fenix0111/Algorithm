// Leetcode 429. N-ary Tree Level Order Traversal
// https://leetcode.com/problems/n-ary-tree-level-order-traversal/
// Runtime: 148ms

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

// need to put all the value in the same level into the array, not only the children of current node
class Solution 
{
public:
    vector<vector<int>> levelOrder(Node* root) 
    {
        vector< vector<int> > ret;
        if (!root)
            return ret;
        
        vector<int> elem(1, root->val);
        ret.push_back(elem);
        
        queue<Node*> q;
        q.push(root);
        
        while (!q.empty())
        {
            vector<Node*> pnode;
            while (!q.empty())
            {
                Node *node = q.front();
                q.pop();
                pnode.push_back(node);
            }
            
            vector<int> level;
            
            for (int j = 0; j < pnode.size(); j++)
            {
                vector<Node*> childs = pnode[j]->children;
                for (int i = 0; i < childs.size(); i++)
                {
                    Node *cnode = childs[i];
                    level.push_back(cnode->val);
                    q.push(cnode);
                }
            }
            
            if (level.size() > 0)
                ret.push_back(level);
        }
        
        return ret;
    }
};

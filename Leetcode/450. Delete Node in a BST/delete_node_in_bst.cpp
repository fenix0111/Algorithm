// Leetcode 450. Delete Node in a BST
// https://leetcode.com/problems/delete-node-in-a-bst/
// time complexity: O(height of tree)
// space complexity: O(1)

// code is messy
// deletion is fair easy because balancing is not required
// nevertheless, a lot of corner cases shoul be taken care

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
    // find new node to replace target node
    // can be max-value node in the left subtree or min-value node in the right subtree
    // here chosen finding min-value node in the right subtree
    TreeNode* findRightMin(TreeNode* node)
    {
        if (!node)
            return NULL;
        
        if (node->left == NULL)
            return node;
        
        return findRightMin(node->left);
    }
    
    TreeNode* findParent(TreeNode* node, int v)
    {
        if (!node)
            return NULL;
        
        if (node->left && node->left->val == v)
            return node;
            
        if (node->right && node->right->val == v)
            return node;
        
        if (node->val < v)
        {
            return findParent(node->right, v);
        }
        else
        {
            return findParent(node->left, v);
        }
    }
    
    TreeNode* findTarget(TreeNode* node, int v)
    {
        if (!node)
            return NULL;
        
        if (node->val < v)
        {
            return findTarget(node->right, v);
        }
        else if (node->val > v)
        {
            return findTarget(node->left, v);
        }
        else
        {
            return node;
        }
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) 
    {
        if (!root)
            return root;
        
        // when the node to be deleted is root node
        if (root->val == key)
        {
            TreeNode* target = root;

            TreeNode* promoted = findRightMin(target->right);
            if (promoted == NULL)
                promoted = target->left;
            
            TreeNode* promotedParent = NULL;
            TreeNode* promotedRight = NULL;
            if (promoted)
            {
                promotedParent = findParent(root, promoted->val);
                promotedRight = promoted->right;
            }

            if (target->left && target->left->val != promoted->val)
                promoted->left = target->left;
            
            if (target->right && target->right->val != promoted->val)
                promoted->right = target->right;
            
            if (promotedParent)
                promotedParent->left = promotedRight;

            return promoted;
        }
        else
        {
            TreeNode* target = findTarget(root, key);
            if (target == NULL)
                return root;

            // parent of target node
            TreeNode* parent = findParent(root, key);
            
            // target node is leaf node
            if (target->left == NULL && target->right == NULL)
            {
                if (key < parent->val)
                    parent->left = NULL;
                else
                    parent->right = NULL;
                
                return root;
            }

            TreeNode* promoted = findRightMin(target->right);
            
            if (!promoted)
                promoted = target->left;
           
            TreeNode* promotedParent = NULL;
            TreeNode* promotedRight = NULL;
            
            if (promoted)
            {
                promotedParent = findParent(root, promoted->val);
                promotedRight = promoted->right;
            }
            
            if (target->left && target->left->val != promoted->val)
                promoted->left = target->left;

            if (target->right && target->right->val != promoted->val)
                promoted->right = target->right;
            
            if (promotedParent)
                promotedParent->left = promotedRight;

            if (promoted)
            {
                if (promoted->val < parent->val)
                    parent->left = promoted;
                else
                    parent->right = promoted;
            }
            else
            {
                if (key < parent->val)
                    parent->left = NULL;
                else
                    parent->right = NULL;
            }
            
            return root;
        }
    }
};

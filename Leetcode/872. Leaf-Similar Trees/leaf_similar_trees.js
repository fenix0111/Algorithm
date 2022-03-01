// Leetcode 872. Leaf-Similar Trees
// https://leetcode.com/problems/leaf-similar-trees/
// time complexity: O(N)
// space complexity: O(N)

/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root1
 * @param {TreeNode} root2
 * @return {boolean}
 */
function collectLeaf(root, leaf) {
    if (root === null) {
        return;
    }
    if (root.left === null && root.right === null) {
        leaf.push(root.val);
        return;
    }
    
    collectLeaf(root.left, leaf);
    collectLeaf(root.right, leaf);
}

var leafSimilar = function(root1, root2) {
    let leaf1 = [];
    let leaf2 = [];
    
    collectLeaf(root1, leaf1);
    collectLeaf(root2, leaf2);
    
    if (leaf1.length != leaf2.length) {
        return false;
    }
    
    for (i = 0; i < leaf1.length; i++) {
        if (leaf1[i] != leaf2[i]) {
            return false;
        }
    }
    
    return true;
};

# Leetcode 965. Univalued Binary Tree
# https://leetcode.com/problems/univalued-binary-tree/

# Definition for a binary tree node.
# class TreeNode
#     attr_accessor :val, :left, :right
#     def initialize(val = 0, left = nil, right = nil)
#         @val = val
#         @left = left
#         @right = right
#     end
# end
# @param {TreeNode} root
# @return {Boolean}
def is_unival_tree(root)
    if root == nil
        return true
    end
        
    if root.left != nil and root.left.val != root.val
        return false
    end
    
    if root.right != nil and root.right.val != root.val
        return false
    end
    
    is_unival_tree(root.left) and is_unival_tree(root.right)
        
end

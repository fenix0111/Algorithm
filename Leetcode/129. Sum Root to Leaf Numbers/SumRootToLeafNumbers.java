// Leetcode 129. Sum Root to Leaf Numbers
// https://leetcode.com/problems/sum-root-to-leaf-numbers/description/
// Runtime: 1ms

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    int sumNumHelper(TreeNode root, int depth, LinkedList<Integer> list) {
        if (null == root) {
            return 0;
        }

        list.add(root.val);

        // for leaf
        if (null == root.left && null == root.right) {
            if (depth > 0) {
                if (list.size() > 1) {
                    int res = 0;
                    for (int i = 0; i < list.size(); i++) {
                        res = res + list.get(i) * (int)Math.pow(10, depth - i);
                    }

                    list.removeLast();
                    return res;
                } else {
                    return 0;
                }
            }
        }

        int left = sumNumHelper(root.left, depth + 1, list);
        int right = sumNumHelper(root.right, depth + 1, list);
        if (list.size() > 1) {
            list.removeLast();
        }

        return left + right;
    }

    public int sumNumbers(TreeNode root) {
        if (null == root) {
            return 0;
        }

        if (null == root.left && null == root.right) {
            return root.val;
        }

        LinkedList<Integer> list = new LinkedList<>();

        return sumNumHelper(root, 0, list);
    }
}
